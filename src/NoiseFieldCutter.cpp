#include "NoiseFieldCutter.h"
#include "Misc.h"

NoiseFieldCutter::NoiseFieldCutter()
{
}


NoiseFieldCutter::~NoiseFieldCutter()
{
}

void NoiseFieldCutter::init()
{
	buffer.allocate( Misc::getDefaultFboSettings() );

	cutoutShader.load( "", ofToDataPath("shader/cutout.fs" ) );
}

ofFbo * NoiseFieldCutter::getCutout( NoiseTexture nt, ofFbo stoneMask )
{
	buffer.begin();
	ofClear( 0 );
	cutoutShader.begin();
	cutoutShader.setUniformTexture( "mask", stoneMask.getTextureReference(), 1 );
	cutoutShader.setUniformTexture( "noi", nt.getBuffer().getTextureReference(), 2 );
	glBegin( GL_QUADS );
	glTexCoord2f( 0, 0 ); glVertex3f( 0, 0, 0 );
	glTexCoord2f( buffer.getWidth(), 0 ); glVertex3f( buffer.getWidth(), 0, 0 );
	glTexCoord2f( buffer.getWidth(), buffer.getHeight() ); glVertex3f( buffer.getWidth(), buffer.getHeight(), 0 );
	glTexCoord2f( 0, buffer.getHeight() );  glVertex3f( 0, buffer.getWidth(), 0 );
	glEnd();
	cutoutShader.end();
	buffer.end();

	return &buffer;
}
