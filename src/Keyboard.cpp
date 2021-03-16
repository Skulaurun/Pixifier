#include "Keyboard.hpp"

#include <windows.h>

bool Keyboard::autoRepeat = true;
Keyboard::Key Keyboard::convertCodeToKey(const unsigned int code) {

	Keyboard::Key key;

	switch (code) {
	case VK_F1:			key = Keyboard::F1;			break;
	case VK_F2:			key = Keyboard::F2;			break;
	case VK_F3:			key = Keyboard::F3;			break;
	case VK_F4:			key = Keyboard::F4;			break;
	case VK_F5:			key = Keyboard::F5;			break;
	case VK_F6:			key = Keyboard::F6;			break;
	case VK_F7:			key = Keyboard::F7;			break;
	case VK_F8:			key = Keyboard::F8;			break;
	case VK_F9:			key = Keyboard::F9;			break;
	case VK_F10:		key = Keyboard::F10;		break;
	case VK_F11:		key = Keyboard::F11;		break;
	case VK_F12:		key = Keyboard::F12;		break;
	case VK_F13:		key = Keyboard::F13;		break;
	case VK_F14:		key = Keyboard::F14;		break;
	case VK_F15:		key = Keyboard::F15;		break;
	case VK_F16:		key = Keyboard::F16;		break;
	case VK_F17:		key = Keyboard::F17;		break;
	case VK_F18:		key = Keyboard::F18;		break;
	case VK_F19:		key = Keyboard::F19;		break;
	case VK_F20:		key = Keyboard::F20;		break;
	case VK_F21:		key = Keyboard::F21;		break;
	case VK_F22:		key = Keyboard::F22;		break;
	case VK_F23:		key = Keyboard::F23;		break;
	case VK_F24:		key = Keyboard::F24;		break;
	case '0':			key = Keyboard::Num0;		break;
	case '1':			key = Keyboard::Num1;		break;
	case '2':			key = Keyboard::Num2;		break;
	case '3':			key = Keyboard::Num3;		break;
	case '4':			key = Keyboard::Num4;		break;
	case '5':			key = Keyboard::Num5;		break;
	case '6':			key = Keyboard::Num6;		break;
	case '7':			key = Keyboard::Num7;		break;
	case '8':			key = Keyboard::Num8;		break;
	case '9':			key = Keyboard::Num9;		break;
	case 'A':			key = Keyboard::A;			break;
	case 'B':			key = Keyboard::B;			break;
	case 'C':			key = Keyboard::C;			break;
	case 'D':			key = Keyboard::D;			break;
	case 'E':			key = Keyboard::E;			break;
	case 'F':			key = Keyboard::F;			break;
	case 'G':			key = Keyboard::G;			break;
	case 'H':			key = Keyboard::H;			break;
	case 'I':			key = Keyboard::I;			break;
	case 'J':			key = Keyboard::J;			break;
	case 'K':			key = Keyboard::K;			break;
	case 'L':			key = Keyboard::L;			break;
	case 'M':			key = Keyboard::M;			break;
	case 'N':			key = Keyboard::N;			break;
	case 'O':			key = Keyboard::O;			break;
	case 'P':			key = Keyboard::P;			break;
	case 'Q':			key = Keyboard::Q;			break;
	case 'R':			key = Keyboard::R;			break;
	case 'S':			key = Keyboard::S;			break;
	case 'T':			key = Keyboard::T;			break;
	case 'U':			key = Keyboard::U;			break;
	case 'V':			key = Keyboard::V;			break;
	case 'W':			key = Keyboard::W;			break;
	case 'X':			key = Keyboard::X;			break;
	case 'Y':			key = Keyboard::Y;			break;
	case 'Z':			key = Keyboard::Z;			break;
	case VK_NUMPAD0:	key = Keyboard::Numpad0;	break;
	case VK_NUMPAD1:	key = Keyboard::Numpad1;	break;
	case VK_NUMPAD2:	key = Keyboard::Numpad2;	break;
	case VK_NUMPAD3:	key = Keyboard::Numpad3;	break;
	case VK_NUMPAD4:	key = Keyboard::Numpad4;	break;
	case VK_NUMPAD5:	key = Keyboard::Numpad5;	break;
	case VK_NUMPAD6:	key = Keyboard::Numpad6;	break;
	case VK_NUMPAD7:	key = Keyboard::Numpad7;	break;
	case VK_NUMPAD8:	key = Keyboard::Numpad8;	break;
	case VK_NUMPAD9:	key = Keyboard::Numpad9;	break;
	case VK_LEFT:		key = Keyboard::Left;		break;
	case VK_RIGHT:		key = Keyboard::Right;		break;
	case VK_UP:			key = Keyboard::Up;			break;
	case VK_DOWN:		key = Keyboard::Down;		break;
	case VK_OEM_1:		key = Keyboard::Semicolon;	break;
	case VK_OEM_COMMA:	key = Keyboard::Comma;		break;
	case VK_OEM_PERIOD:	key = Keyboard::Period;		break;
	case VK_OEM_7:		key = Keyboard::Quote;		break;
	case VK_OEM_2:		key = Keyboard::Slash;		break;
	case VK_OEM_5:		key = Keyboard::Backslash;	break;
	case VK_OEM_3:		key = Keyboard::Tilde;		break;
	case VK_OEM_PLUS:	key = Keyboard::Equal;		break;
	case VK_OEM_MINUS:	key = Keyboard::Hyphen;		break;
	case VK_OEM_4:		key = Keyboard::LBracket;	break;
	case VK_OEM_6:		key = Keyboard::RBracket;	break;
	case VK_ESCAPE:		key = Keyboard::Escape;		break;
	case VK_SPACE:		key = Keyboard::Space;		break;
	case VK_RETURN:		key = Keyboard::Enter;		break;
	case VK_BACK:		key = Keyboard::Backspace;	break;
	case VK_TAB:		key = Keyboard::Tab;		break;
	case VK_PRIOR:		key = Keyboard::PageUp;		break;
	case VK_NEXT:		key = Keyboard::PageDown;	break;
	case VK_END:		key = Keyboard::End;		break;
	case VK_HOME:		key = Keyboard::Home;		break;
	case VK_INSERT:		key = Keyboard::Insert;		break;
	case VK_DELETE:		key = Keyboard::Delete;		break;
	case VK_PAUSE:		key = Keyboard::Pause;		break;
	case VK_APPS:		key = Keyboard::Menu;		break;
	case VK_LCONTROL:	key = Keyboard::LControl;	break;
	case VK_RCONTROL:	key = Keyboard::RControl;	break;
	case VK_LSHIFT:		key = Keyboard::LShift;		break;
	case VK_RSHIFT:		key = Keyboard::RShift;		break;
	case VK_LMENU:		key = Keyboard::LAlt;		break;
	case VK_RMENU:		key = Keyboard::RAlt;		break;
	case VK_LWIN:		key = Keyboard::LSystem;	break;
	case VK_RWIN:		key = Keyboard::RSystem;	break;
	case VK_ADD:		key = Keyboard::Add;		break;
	case VK_SUBTRACT:	key = Keyboard::Subtract;	break;
	case VK_MULTIPLY:	key = Keyboard::Multiply;	break;
	case VK_DIVIDE:		key = Keyboard::Divide;		break;
	default:			key = Keyboard::Null;		break;
	}

	return key;

}
unsigned int Keyboard::convertKeyToCode(const Keyboard::Key key) {

	unsigned int code;

	switch (key) {
	case Keyboard::F1:			code = VK_F1;			break;
	case Keyboard::F2:			code = VK_F2;			break;
	case Keyboard::F3:			code = VK_F3;			break;
	case Keyboard::F4:			code = VK_F4;			break;
	case Keyboard::F5:			code = VK_F5;			break;
	case Keyboard::F6:			code = VK_F6;			break;
	case Keyboard::F7:			code = VK_F7;			break;
	case Keyboard::F8:			code = VK_F8;			break;
	case Keyboard::F9:			code = VK_F9;			break;
	case Keyboard::F10:			code = VK_F10;			break;
	case Keyboard::F11:			code = VK_F11;			break;
	case Keyboard::F12:			code = VK_F12;			break;
	case Keyboard::F13:			code = VK_F13;			break;
	case Keyboard::F14:			code = VK_F14;			break;
	case Keyboard::F15:			code = VK_F15;			break;
	case Keyboard::F16:			code = VK_F16;			break;
	case Keyboard::F17:			code = VK_F17;			break;
	case Keyboard::F18:			code = VK_F18;			break;
	case Keyboard::F19:			code = VK_F19;			break;
	case Keyboard::F20:			code = VK_F20;			break;
	case Keyboard::F21:			code = VK_F21;			break;
	case Keyboard::F22:			code = VK_F22;			break;
	case Keyboard::F23:			code = VK_F23;			break;
	case Keyboard::F24:			code = VK_F24;			break;
	case Keyboard::Num0:		code = '0';				break;
	case Keyboard::Num1:		code = '1';				break;
	case Keyboard::Num2:		code = '2';				break;
	case Keyboard::Num3:		code = '3';				break;
	case Keyboard::Num4:		code = '4';				break;
	case Keyboard::Num5:		code = '5';				break;
	case Keyboard::Num6:		code = '6';				break;
	case Keyboard::Num7:		code = '7';				break;
	case Keyboard::Num8:		code = '8';				break;
	case Keyboard::Num9:		code = '9';				break;
	case Keyboard::A:			code = 'A';				break;
	case Keyboard::B:			code = 'B';				break;
	case Keyboard::C:			code = 'C';				break;
	case Keyboard::D:			code = 'D';				break;
	case Keyboard::E:			code = 'E';				break;
	case Keyboard::F:			code = 'F';				break;
	case Keyboard::G:			code = 'G';				break;
	case Keyboard::H:			code = 'H';				break;
	case Keyboard::I:			code = 'I';				break;
	case Keyboard::J:			code = 'J';				break;
	case Keyboard::K:			code = 'K';				break;
	case Keyboard::L:			code = 'L';				break;
	case Keyboard::M:			code = 'M';				break;
	case Keyboard::N:			code = 'N';				break;
	case Keyboard::O:			code = 'O';				break;
	case Keyboard::P:			code = 'P';				break;
	case Keyboard::Q:			code = 'Q';				break;
	case Keyboard::R:			code = 'R';				break;
	case Keyboard::S:			code = 'S';				break;
	case Keyboard::T:			code = 'T';				break;
	case Keyboard::U:			code = 'U';				break;
	case Keyboard::V:			code = 'V';				break;
	case Keyboard::W:			code = 'W';				break;
	case Keyboard::X:			code = 'X';				break;
	case Keyboard::Y:			code = 'Y';				break;
	case Keyboard::Z:			code = 'Z';				break;
	case Keyboard::Numpad0:		code = VK_NUMPAD0;		break;
	case Keyboard::Numpad1:		code = VK_NUMPAD1;		break;
	case Keyboard::Numpad2:		code = VK_NUMPAD2;		break;
	case Keyboard::Numpad3:		code = VK_NUMPAD3;		break;
	case Keyboard::Numpad4:		code = VK_NUMPAD4;		break;
	case Keyboard::Numpad5:		code = VK_NUMPAD5;		break;
	case Keyboard::Numpad6:		code = VK_NUMPAD6;		break;
	case Keyboard::Numpad7:		code = VK_NUMPAD7;		break;
	case Keyboard::Numpad8:		code = VK_NUMPAD8;		break;
	case Keyboard::Numpad9:		code = VK_NUMPAD9;		break;
	case Keyboard::Left:		code = VK_LEFT;			break;
	case Keyboard::Right:		code = VK_RIGHT;		break;
	case Keyboard::Up:			code = VK_UP;			break;
	case Keyboard::Down:		code = VK_DOWN;			break;
	case Keyboard::Semicolon:	code = VK_OEM_1;		break;
	case Keyboard::Comma:		code = VK_OEM_COMMA;	break;
	case Keyboard::Period:		code = VK_OEM_PERIOD;	break;
	case Keyboard::Quote:		code = VK_OEM_7;		break;
	case Keyboard::Slash:		code = VK_OEM_2;		break;
	case Keyboard::Backslash:	code = VK_OEM_5;		break;
	case Keyboard::Tilde:		code = VK_OEM_3;		break;
	case Keyboard::Equal:		code = VK_OEM_PLUS;		break;
	case Keyboard::Hyphen:		code = VK_OEM_MINUS;	break;
	case Keyboard::LBracket:	code = VK_OEM_4;		break;
	case Keyboard::RBracket:	code = VK_OEM_6;		break;
	case Keyboard::Escape:		code = VK_ESCAPE;		break;
	case Keyboard::Space:		code = VK_SPACE;		break;
	case Keyboard::Enter:		code = VK_RETURN;		break;
	case Keyboard::Backspace:	code = VK_BACK;			break;
	case Keyboard::Tab:			code = VK_TAB;			break;
	case Keyboard::PageUp:		code = VK_PRIOR;		break;
	case Keyboard::PageDown:	code = VK_NEXT;			break;
	case Keyboard::End:			code = VK_END;			break;
	case Keyboard::Home:		code = VK_HOME;			break;
	case Keyboard::Insert:		code = VK_INSERT;		break;
	case Keyboard::Delete:		code = VK_DELETE;		break;
	case Keyboard::Pause:		code = VK_PAUSE;		break;
	case Keyboard::Menu:		code = VK_APPS;			break;
	case Keyboard::LControl:	code = VK_LCONTROL;		break;
	case Keyboard::RControl:	code = VK_RCONTROL;		break;
	case Keyboard::LShift:		code = VK_LSHIFT;		break;
	case Keyboard::RShift:		code = VK_RSHIFT;		break;
	case Keyboard::LAlt:		code = VK_LMENU;		break;
	case Keyboard::RAlt:		code = VK_RMENU;		break;
	case Keyboard::LSystem:		code = VK_LWIN;			break;
	case Keyboard::RSystem:		code = VK_RWIN;			break;
	case Keyboard::Add:			code = VK_ADD;			break;
	case Keyboard::Subtract:	code = VK_SUBTRACT;		break;
	case Keyboard::Multiply:	code = VK_MULTIPLY;		break;
	case Keyboard::Divide:		code = VK_DIVIDE;		break;
	default:					code = 0;				break;
	}

	return code;

}
bool Keyboard::isKeyPressed(const Key key) {
	return (GetAsyncKeyState(Keyboard::convertKeyToCode(key)) & 0x8000) != 0;
}
void Keyboard::setAutoRepeat(const bool autoRepeat) {
	Keyboard::autoRepeat = autoRepeat;
}
bool Keyboard::getAutoRepeat() {
	return autoRepeat;
}
