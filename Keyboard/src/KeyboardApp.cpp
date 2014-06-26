#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class KeyboardApp : public AppNative {
  public:
	void setup();
	void keyDown( KeyEvent event );
	void keyUp( KeyEvent event );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	bool KEY_W, KEY_S, KEY_A, KEY_D, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE;
	int x, y;
};

void KeyboardApp::setup()
{
	KEY_W = KEY_S = KEY_A = KEY_D = KEY_UP = KEY_DOWN = KEY_LEFT = KEY_RIGHT = KEY_SPACE = false;
}

void KeyboardApp::mouseDown( MouseEvent event )
{
}

void KeyboardApp::keyDown( KeyEvent event )
{
	switch(event.getChar())
	{
	case 'w':
		KEY_W = true;
		break;
	case 's':
		KEY_S = true;
		break;
	case 'a':
		KEY_A = true;
		break;
	case 'd':
		KEY_D = true;
		break;
	}
	switch(event.getCode())
	{
	case KeyEvent::KEY_UP:
		KEY_UP = true;
	case 276:
		KEY_LEFT = true;
		break;
	case KeyEvent::KEY_RIGHT:
		KEY_RIGHT = true;
		break;
	case KeyEvent::KEY_SPACE:
		KEY_SPACE = true;
		break;
	}
}

void KeyboardApp::keyUp( KeyEvent event )
{
	switch(event.getChar())
	{
	case 'w':
		KEY_W =false;
		break;
	case 's':
		KEY_S = false;
		break;
	case 'a':
		KEY_A = false;
		break;
	case 'd':
		KEY_D = false;
		break;
	}
	switch(event.getCode())
	{
	case KeyEvent::KEY_UP:
		KEY_UP = false;
	case 276:
		KEY_LEFT = false;
		break;
	case KeyEvent::KEY_RIGHT:
		KEY_RIGHT = false;
		break;
	case KeyEvent::KEY_SPACE:
		KEY_SPACE = false;
		break;
	}
}
void KeyboardApp::update()
{
	if(KEY_UP || KEY_W) y -= 5;
	if(KEY_DOWN || KEY_S) y += 5;
	if(KEY_LEFT || KEY_A) x -= 5;
	if(KEY_RIGHT || KEY_D) x += 5;
}

void KeyboardApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	if(KEY_SPACE) {
		gl::color(Color(0, 1, 0) );
		gl::drawSolidCircle( Vec2f( x,y ), 20, 5);
	} else {
		gl::color(Color(1, 0, 0));
		gl::drawSolidRect( Rectf( x - 10, y -10, x + 10, y + 10) );
	}
}

CINDER_APP_NATIVE( KeyboardApp, RendererGl )
