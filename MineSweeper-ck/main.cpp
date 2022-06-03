#include "main.h"

wxBEGIN_EVENT_TABLE(main, wxFrame)

wxEND_EVENT_TABLE()
main::main() : wxFrame(nullptr, wxID_ANY, "MineSweeper", wxPoint(30,30),wxSize(800, 600))
{
	btn = new wxButton*[Width * Height];
	wxGridSizer* grid = new wxGridSizer(Width, Height, 0, 0);

	field = new int[Width * Height];

	for (size_t i = 0; i < Width; i++)
	{
		for (size_t o = 0; o < Height; o++)
		{
			btn[o * Width + i] = new wxButton(this,1000 + (o * Width + i));
			grid->Add(btn[o * Width + i], 1, wxEXPAND | wxALL);

			btn[o * Width + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &main::OnButtonClicked, this);
			field[o * Width + i] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

main::~main()
{
	delete[] btn;
}

void main::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % Width;
	int y = (evt.GetId() - 10000) % Width;
	if (firstclick)
	{
		int mines = 30;

		while (mines)
		{
			int pointx = rand() % Width;
			int pointy = rand() % Height;

			if (field[pointy * Width + pointx] == 0 && pointx != x && pointy != y)
			{
				field[pointy * Width + pointx] = -1;
				mines--;
			}
		}
		firstclick = false;
	}
	btn[y * Width + x]->Enable(false);

	if (field[y * Width + x] == -1)
	{
		wxMessageBox("GAME OVER");

		firstclick = true;
		for (size_t i = 0; i < Width; i++)
		{
			for (size_t o = 0; o < Height; o++)
			{
				field[o * Width + i] = 0;
				btn[o * Width + i] -> SetLabel("");
				btn[o * Width + i]->Enable(true);
			}
		}
	}
	else
	{
		int minecount = 0;
		for (size_t i = 0; i < Width; i++)
		{
			for (size_t o = 0; o < Height; o++)
			{
				if (x + i >= 0 && x + i < Width && y + o >= 0 && y + o < Height)
				{

					if (field[(i + o) * Width + (x + i)] == -1)
					{
						minecount++;
					}
				}
			}
		}
		if (minecount > 0)
		{
			btn[y * Width + x]->SetLabel(std::to_string(minecount));
		}
	}
	evt.Skip();
}