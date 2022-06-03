
#include "minesweeper.h"

wxIMPLEMENT_APP(minesweeper);

minesweeper::minesweeper()
{

}

minesweeper::~minesweeper()
{

}

bool minesweeper::OnInit()
{
	m_frame1 = new main();
	m_frame1->Show();

	return true;
}