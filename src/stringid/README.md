#StringID - A compile-time hashed string

The StringID class allows for hashing of **compile-time** and **run-time** strings. This comes in handy for applications where performance is key
by avoiding costly string comparisons. Instead they are replaced by rather simple and cheap integer-integer comparisons. To enable this, the StrindID
class computes a hash of the string using the FNV1 hashing algorithm (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)

## Compile-time variant

The compile-time variant is based on a constexpr template meta-program that allows the compiler to compute the hash of string literals (type: const char[SIZE])
during compilation. The template meta-programs use recursion and template specialization to allow this to work.

## Run-time variant

The StringID also allows for hashing of const char* so it is also possible to use the StrindID together with std::strings (using the c_str() method to get
a const char* to the internal string).


## Example

```
cry::StringID hashed_str_one("StringLiteral");
cry::StringID hashed_str_two("StringLiteral");

assert(hashed_str_one.GetHash() == hashed_str_two.GetHash());

std::string runtimeStr("Foo");
cry::StringID hashed_str_three(runtimeStr.c_str());
cry::StringID hashed_str_four("Foo");

assert(hashed_str_three.GetHash() == hashed_str_four.GetHash());

// The compile-time hashing also allows to use the hashed strings in switch statements
switch(hashed_str_one.GetHash())
{
	case cry::GenerateHash("StringLiteral"):
	{
		// Do sth if StringLiteral
		break;
	}
	
	case cry::GenerateHash("Foo"):
	{
		// Do sth if Foo
		break;
	}
}

```