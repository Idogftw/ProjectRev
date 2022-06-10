# Project Rev

## Description
The game portion of this projects theme will be some sort of horror type, none specific but that's the basis.
As for the engine there is no exact direction for it, I am just simply going to try and do some of the planned features shown in the Trello and then go from there. I would like to implement the basics of a window, events, input and rendering to start off and then go on the specific features below and on the Trello linked below.

## Planned Features (Engine)
- Skeletal Animation
- Tessellation
    - Normal/Parallax Mapping
- Vulkan and OpenGL backends (OpenGL starting out)
- Shadow Mapping (Cascaded Shadow Mapping)
- Deferred Lighting (Possibly Forward+ instead)
- SSAO
- Bloom/HDR
- BSP Mapping support
- **More on Trello below!!**

**_Suggestions welcome!_**

### [Trello](https://trello.com/b/IBEsloS2/project-rev)

## Instructions to Run
First you're going to need a couple libraries:
- [FBX SDK 2020](https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-0)
- [DevIL](http://openil.sourceforge.net/download.php)
- [Glad](https://glad.dav1d.de/)
    - Current Settings:
        - GL: Version 4.5
        - Profile: Compatibility
- [nlohmann](https://github.com/nlohmann/json)

You can download the files from [THIS](https://mega.nz/file/Xz5BCRaD#6xANPkmEiwerqLxhj1kN-5Cd60YL34pRAAAAAAAAAAA) link and just open it and drag it in to the Gateway directory. If you prefer to download them yourselves, feel free to use links above.

Lastly, you will need to download the [Premake5](https://premake.github.io/download) executable and place in the directory of the premake lua file.

After everything is downloaded and put in their correct directories you can then open a cmd prompt in the directory of the premake lua file and run 'premake.exe vs2017'

## Notes
**Everything in this README and project itself is NOT set in stone so if you see something you don't like as far as a formatting, C++ standards and conventions go, not all will stay and will be subject to change based on input from others. I am simply one person and am just trying to do a fun project to share with others and am by no means a professional programmer or mathematician, there will be mistakes and possibly bad code/math but help and guidance is always welcome, thanks!**

**Also, this project will not become similar to that of Unity, Unreal, Godot, or any of those editors being all in one and it will not have an ECS or some of what modern engines have. This will be an old school type of engine similar to that of Doom 3 and COD in the sense of using a def file for entity types and in other ways, modders of those games will have an idea of what I mean by how similar I would like it to be. It will have modern techniques for some stuff but not everything, the determining factor of what will, will be a see it as it goes.**

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Linux and Mac users welcome to help setup and modify the builds and what not to include said Operating Systems as I don't have or use either products.

## License
[MIT](https://choosealicense.com/licenses/mit/)