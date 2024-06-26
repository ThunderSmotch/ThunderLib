export module ThunderEngine.WindowProps;

import ThunderEngine.Base;
import std;

export namespace ThunderEngine
{
/// <summary>
/// Window Properties
/// </summary>
struct WindowProps
{
	string title;
	u32 width;
	u32 height;

	WindowProps(const string& title = "ThunderEngine", u32 width = 1280, u32 height = 720)
		:title(title), width(width), height(height)
	{}
};
}