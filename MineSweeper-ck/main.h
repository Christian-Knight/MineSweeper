#pragma once
#include "wx/wx.h"
class main : public wxFrame
{
public:
	main();
	~main();
	int Width = 10;
	int Height = 10;
	wxButton **btn;
	int* field = nullptr;
	bool firstclick = true;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

