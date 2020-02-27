#pragma once

#include "GLView.h"
#include "NetMessengerClient.h"
#include "NetMsgAntGsSetback.h"
#include "NetMsgText.h"
#include "CloneTrooper.h"
#include "WOFTGLString.h"
//#include "PxPhysicsAPI.h"
//#include "PhysX.h"
//#include <irrKlang.h>

namespace Aftr
{
   class Camera;

class GLViewNewModule : public GLView
{
public:
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );

   CloneTrooper* clone;
   WOFTGLString* text;
   //PhysicsCreate* engine;

protected:
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate();
   NetMessengerClient* client;
   bool isTyping = false;
};

/** \} */

} //namespace Aftr
