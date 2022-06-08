#pragma once

namespace Gateway
{
#define REG_KEY(key, code) Key_##key = code
#define REG_MOUSE(button) MouseButton_##button
	
	enum DeviceTypes
	{
		DeviceType_Keyboard,
		DeviceType_Mouse,
		DeviceType_Gamepad,
		DeviceType_Last
	};

	enum KeyMods
	{
		KeyMod_None = 0x00,
		KeyMod_Shift = 0x01,
		KeyMod_Ctrl = 0x02,
		Keymod_Alt = 0x04,
		Keymod_Last = 0x08
	};

	enum Keys
	{
		REG_KEY(None, 0x0),

		REG_KEY(Backspace, 0x08),
		REG_KEY(Tab, 0x09),
		REG_KEY(Clear, 0x0C),
		REG_KEY(Enter, 0x0D),
		REG_KEY(Shift, 0x10),
		REG_KEY(Ctrl, 0x11),
		REG_KEY(Alt, 0x12),
		REG_KEY(Pause, 0x13),
		REG_KEY(CapsLk, 0x14),
		REG_KEY(Escape, 0x1B),
		REG_KEY(Convert, 0x1C),
		REG_KEY(NonConvert, 0x1D),
		REG_KEY(Accept, 0x1E),
		REG_KEY(Mode, 0x1F),
		REG_KEY(Space, 0x20),
		REG_KEY(PgUp, 0x21),
		REG_KEY(PgDown, 0x22),
		REG_KEY(End, 0x23),
		REG_KEY(Home, 0x24),
		REG_KEY(Left, 0x25),
		REG_KEY(Up, 0x26),
		REG_KEY(Right, 0x27),
		REG_KEY(Down, 0x28),
		REG_KEY(Select, 0x29),
		REG_KEY(Print, 0x2A),
		REG_KEY(Execute, 0x2B),
		REG_KEY(PrtScr, 0x2C),
		REG_KEY(Insert, 0x2D),
		REG_KEY(Delete, 0x2E),
		REG_KEY(Help, 0x2F),

		REG_KEY(0, 0x30),
		REG_KEY(1, 0x31),
		REG_KEY(2, 0x32),
		REG_KEY(3, 0x33),
		REG_KEY(4, 0x34),
		REG_KEY(5, 0x35),
		REG_KEY(6, 0x36),
		REG_KEY(7, 0x37),
		REG_KEY(8, 0x38),
		REG_KEY(9, 0x39),

		REG_KEY(A, 0x41),
		REG_KEY(B, 0x42),
		REG_KEY(C, 0x43),
		REG_KEY(D, 0x44),
		REG_KEY(E, 0x45),
		REG_KEY(F, 0x46),
		REG_KEY(G, 0x47),
		REG_KEY(H, 0x48),
		REG_KEY(I, 0x49),
		REG_KEY(J, 0x4A),
		REG_KEY(K, 0x4B),
		REG_KEY(L, 0x4C),
		REG_KEY(M, 0x4D),
		REG_KEY(N, 0x4E),
		REG_KEY(O, 0x4F),
		REG_KEY(P, 0x50),
		REG_KEY(Q, 0x51),
		REG_KEY(R, 0x52),
		REG_KEY(S, 0x53),
		REG_KEY(T, 0x54),
		REG_KEY(U, 0x55),
		REG_KEY(V, 0x56),
		REG_KEY(W, 0x57),
		REG_KEY(X, 0x58),
		REG_KEY(Y, 0x59),
		REG_KEY(Z, 0x5A),

		REG_KEY(LWIN, 0x5B),
		REG_KEY(RWIN, 0x5C),
		REG_KEY(App, 0x5D),

		REG_KEY(Pad_0, 0x60),
		REG_KEY(Pad_1, 0x61),
		REG_KEY(Pad_2, 0x62),
		REG_KEY(Pad_3, 0x63),
		REG_KEY(Pad_4, 0x64),
		REG_KEY(Pad_5, 0x65),
		REG_KEY(Pad_6, 0x66),
		REG_KEY(Pad_7, 0x67),
		REG_KEY(Pad_8, 0x68),
		REG_KEY(Pad_9, 0x69),
		
		REG_KEY(Multiply, 0x6A),
		REG_KEY(Add, 0x6B),
		REG_KEY(Pipe, 0x6C),
		REG_KEY(Subtract, 0x6D),
		REG_KEY(Decimal, 0x6E),
		REG_KEY(Divide, 0x6F),

		REG_KEY(F1, 0x70),
		REG_KEY(F2, 0x71),
		REG_KEY(F3, 0x72),
		REG_KEY(F4, 0x73),
		REG_KEY(F5, 0x74),
		REG_KEY(F6, 0x75),
		REG_KEY(F7, 0x76),
		REG_KEY(F8, 0x77),
		REG_KEY(F9, 0x78),
		REG_KEY(F10, 0x79),
		REG_KEY(F11, 0x7A),
		REG_KEY(F12, 0x7B),
		REG_KEY(F13, 0x7C),
		REG_KEY(F14, 0x7D),
		REG_KEY(F15, 0x7E),
		REG_KEY(F16, 0x7F),
		REG_KEY(F17, 0x80),
		REG_KEY(F18, 0x81),
		REG_KEY(F19, 0x82),
		REG_KEY(F20, 0x83),
		REG_KEY(F21, 0x84),
		REG_KEY(F22, 0x85),
		REG_KEY(F23, 0x86),
		REG_KEY(F24, 0x87),

		REG_KEY(NumLk, 0x90),
		REG_KEY(ScrLk, 0x91),
		REG_KEY(Equal, 0x92),

		REG_KEY(LeftShift, 0xA0),
		REG_KEY(RightShift, 0xA1),
		REG_KEY(LeftCtrl, 0xA2),
		REG_KEY(RightCtrl, 0xA3),
		REG_KEY(LeftAlt, 0xA4),
		REG_KEY(RightAlt, 0xA5),
		
		REG_KEY(Colon, 0xBA),
		REG_KEY(Plus, 0xBB),
		REG_KEY(Comma, 0xBC),
		REG_KEY(Minus, 0xBD),
		REG_KEY(Period, 0xBE),
		REG_KEY(Slash, 0xBF),
		REG_KEY(Tilde, 0xC0),

		Key_Last
	};

	enum MouseButtons
	{
		REG_MOUSE(Left),
		REG_MOUSE(Right),
		REG_MOUSE(Wheel),
		REG_MOUSE(WheelUp),
		REG_MOUSE(WheelDown),
		REG_MOUSE(Button6),
		REG_MOUSE(Button7),
		REG_MOUSE(Button8),
		REG_MOUSE(Button9),
		REG_MOUSE(Last)
	};
};