# CrystallineBox - A research rendering engine for Vulkan and D3D12
This rendering engine should serve as a research project to get familiar with the relatively new graphics APIs of Vulkan and D3D12 on the windows platform.
The basic idea is to fist implement a deferred renderer using Vulkan and implement several graphics programming techniques with it.
Later the same functionality should be available with D3D12 as a backend. In the end it is planned to examine some newer graphics hardware
features such as Ray/Path tracing and NVidia's mesh and task shaders as well as 'Variable Rate Shading'.

### Idea behind this

The idea why this is started is to first, re-strengthen the knowledge of computer graphics development and engine dev (currently I mostly work on already feature-complete engines and UE4), and second to document the creation process.
It is planned that for most of the bullet points below there will be a related blog post at www.hic-sunt-vulpes.com. One reason for this is to keep up motivation while working on this by discussing with others what was done and why.
Another reason for this project is that it should serve as a tabula rasa for several future projects which will focus more on shader programming. With the CrystallineBox as a basic framework it should then be possible to focus on the
development of shader projects (thinking procedural geometry, compute shaders, advanced effects, ...) without having to recreate a basic rendering framework for all those projects.

### Milestones

We will first start to focus on Vulkan because it's more familiar to us than D3D12 and will later extend the Vulkan renderer to support multiple backends. This will serve as a good lesson on how to extend a renderer by another backend
and what problems we are going to face in that process. Nevertheless we will already respect the idea of supporting multiple backends during the Vulkan development.

- [ ] Create a WIN32 window, handle the most important incoming messages and provide a Vulkan surface for that window
- [ ] Make the application render the obligatory 'Hello Triangle'
- [ ] Handle window resizing, different resolutions and window modes (fullscreen, windowed, fullscreen borderless windowed) by re-creating the swapchain
- [ ] Vulkan renderer can display textured 3D models in a re-usable way
    - Processes for creating buffers, resource views, bindings and synchronization as well as lifetime management is in place

- [ ] TBA 

### Graphic features to implement

- [ ] Texturing and normal mapping
- [ ] Directional, point and spot lights
- [ ] Cascading shadow maps (with VSM - Variance Shadow Mapping - as the algorithm for soft shadows)
    - Maybe also implement PCF (Percentage Closest Filtering) and show possible artifacts and difference to VSM
- [ ] Screen-space reflections
- [ ] Ambient occlusion (maybe TSSAO)
- [ ] Anti-aliasing modes
    - Expose different modes to also show difference between Super- and Multisampling (and their respective costs)
- [ ] Collection of PostFX
    - [ ] Bloom
	- [ ] Depth of field
	- [ ] Lensflare
	- [ ] Dirtmask
- [ ] Add a PBR branch that showcases the use of BRDFs

### Additional/Optional engine capabilities

- [ ] Support asset hot-reloading
    - [ ] Shaders
	- [ ] Meshes & textures
- [ ] Integrate RenderDoc for advanced debugging
- [ ] Implement a logging framework (loglevels, channels, output directions)
- [ ] Asset pipeline to optimize meshes, textures (compression) and more
- [ ] Support scenes as binary or text files (maybe some mix to support merging but also have the advantages of binary files)
- [ ] Debug utilities to display G-Buffer layers, wireframes, camera frustum, light frustums, ...
- [ ] Multi-threaded creation of rendering commands (buckets sorted by pipeline state, materials, ... to speedup rendering)