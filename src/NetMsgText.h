#pragma once

#include "NetMsg.h"
#include "Vector.h"
#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

class NetMsgText : public NetMsg
{
public:
   NetMsgMacroDeclaration( NetMsgText );

   NetMsgText(const std::string text = "");
   virtual ~NetMsgText();
   virtual bool toStream( NetMessengerStreamBuffer& os ) const;
   virtual bool fromStream( NetMessengerStreamBuffer& is );
   virtual void onMessageArrived();
   virtual std::string toString() const;

protected:
    std::string netMsgText;

};

} //namespace Aftr

#endif
