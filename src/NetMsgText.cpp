#include "NetMsgText.h"
#include "Model.h"
#include "GLViewNewModule.h"

using namespace Aftr;

NetMsgMacroDefinition( NetMsgText );

NetMsgText::NetMsgText(const std::string text)
{
   this->netMsgText = text;
}

NetMsgText::~NetMsgText()
{
}

bool NetMsgText::toStream( NetMessengerStreamBuffer& os ) const
{
   os << this->netMsgText;
   return true;
}

bool NetMsgText::fromStream( NetMessengerStreamBuffer& is )
{
   is >> this->netMsgText;;
   return true;
}

void NetMsgText::onMessageArrived()
{
   ((GLViewNewModule*)ManagerGLView::getGLView()) -> text -> setText(this -> netMsgText);

   std::cout << this->toString() << std::endl;
}

std::string NetMsgText::toString() const
{
   std::stringstream ss;

   ss << NetMsg::toString();
   ss << "Message: " << this->netMsgText << "...\n";

   return ss.str();
}
