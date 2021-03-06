#include "ofMain.h"
#include "testApp.h"
#include "GrowingBrushStokeAct.h"
#include "StopMotionStonesAct.h"
#include "ActSequencer.h"
#include "ofAppGlutWindow.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main(){
	ofSetWorkingDirectoryToDefault();
	ofAppGlutWindow window;
	window.setWindowAlwaysOnTop();
	//window.setGlutDisplayString( "rgba double samples>=4" );
	//window.setGlutDisplayString( "rgba double depth samples>=4" );
	//window.setGlutDisplayString( "rgba double depth alpha samples>=4" );
	//window.setNumSamples( 8 );
	//ofSetupOpenGL( &window, 1920, 1080, OF_WINDOW );			// <-------- setup the GL context
	ofSetupOpenGL( &window, 1280, 800, OF_FULLSCREEN );
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	// ofRunApp( new testApp() );
	// act 1
	//ofRunApp( new StopMotionStonesApp() );

	// act 2
	//ofRunApp( new GrowingBrushStokeApp() );

	// sequencer
	ofRunApp( new ActSequencer() );
}
