#pragma once

#include "wx/wx.h"
#include "main.h"
class minesweeper : public wxApp
{
public:
	minesweeper();
	~minesweeper();
	virtual bool OnInit();

private:
	main* m_frame1 = nullptr;

};
