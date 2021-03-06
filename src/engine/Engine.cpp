#include "VGUI1/CVGUI1App.h"

#include "Engine.h"

CCommandBuffer g_CommandBuffer;

cvar::CCVarSystem g_CVar;

CEngine g_Engine;

CVideo g_Video;

//Constructor self registers itself for retrieval with vgui::App::getInstance.
static CVGUI1App g_VGUI1App;

CVGUI1Surface* g_pVGUI1Surface = nullptr;

IFileSystem2* g_pFileSystem = nullptr;

CSteamAPIContext g_SteamAPIContext;

font::CFontManager g_FontManager;

CMapManager g_MapManager;
