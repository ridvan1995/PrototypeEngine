#ifndef ENGINE_VGUI1_CVGUI1SURFACE_H
#define ENGINE_VGUI1_CVGUI1SURFACE_H

#include <memory>
#include <vector>

#include <GL/glew.h>

#include <SDL2/SDL.h>

#include <VGUI_SurfaceBase.h>

#include "VGUI1/font/CFont.h"

namespace vgui
{
class BitmapTGA;
}

class CVGUI1Surface : public vgui::SurfaceBase
{
private:
	typedef std::vector<std::unique_ptr<vgui::CFont>> Fonts_t;

public:
	CVGUI1Surface( vgui::Panel* embeddedPanel );
	~CVGUI1Surface();

	void setTitle( const char* title ) override;
	bool setFullscreenMode( int wide, int tall, int bpp ) override;
	void setWindowedMode() override;
	void setAsTopMost( bool state ) override;
	void createPopup( vgui::Panel* embeddedPanel ) override;
	bool hasFocus() override;
	bool isWithin( int x, int y ) override;
	int  createNewTextureID( void ) override;
	void GetMousePos( int &x, int &y ) override;

	void drawSetColor( int r, int g, int b, int a ) override;
	void drawFilledRect( int x0, int y0, int x1, int y1 ) override;
	void drawOutlinedRect( int x0, int y0, int x1, int y1 ) override;
	void drawSetTextFont( vgui::Font* font ) override;
	void drawSetTextColor( int r, int g, int b, int a ) override;
	void drawSetTextPos( int x, int y ) override;
	void drawPrintText( const char* text, int textLen ) override;
	void drawSetTextureRGBA( int id, const char* rgba, int wide, int tall ) override;
	void drawSetTexture( int id ) override;
	void drawTexturedRect( int x0, int y0, int x1, int y1 ) override;
	void invalidate( vgui::Panel *panel ) override;
	void enableMouseCapture( bool state ) override;
	void setCursor( vgui::Cursor* cursor ) override;
	void swapBuffers() override;
	void pushMakeCurrent( vgui::Panel* panel, bool useInsets ) override;
	void popMakeCurrent( vgui::Panel* panel ) override;
	void applyChanges() override;

	void HandleSDLEvent( SDL_Event& event );

private:
	int m_iOffsets[ 2 ] = { 0, 0 };

	GLuint m_CurrentTexture = 0;

	uchar m_DrawColor[ 4 ];

	Fonts_t m_Fonts;

	vgui::CFont* m_pActiveFont = nullptr;

	uchar m_TextDrawColor[ 4 ] = { 255, 255, 255, 255 };

	int m_iTextXPos = 0;
	int m_iTextYPos = 0;

	vgui::BitmapTGA* m_pEmulatedMouseImage = nullptr;

	static SDL_Cursor* m_Cursors[ 20 ];

	SDL_Cursor* m_pCursor = nullptr;

	bool m_bCursorVisible = false;

	bool m_bCursorLocked = false;
};

#endif //ENGINE_VGUI1_CVGUI1SURFACE_H
