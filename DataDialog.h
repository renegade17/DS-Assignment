#ifndef DIALOG_H
#define DIALOG_H

 

struct record
{
	int      clientID;
	wxString name;
	wxString surname;
	wxString country;
	wxString season;
	wxString trip;
};
typedef struct record Record;

//Define a dialog box class with 5 data fields (Attributes) - inheriting from wxDialog, of course 
class DataDialog: public wxDialog
  {
	 public:
		DataDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
			  
		wxSpinCtrl* ClientIDEditBox;
		wxTextCtrl* NameEditBox;
		wxTextCtrl* SurnameEditBox;
        wxTextCtrl* CountryEditBox;
		
		wxRadioButton* internet;			// For radio buttons
		wxRadioButton* gifted;
		wxRadioButton* walkin;
		wxRadioButton* telephone;
		
		
		wxComboBox* seasonsCombo;         //For a drop-down list
  };

  
  
DataDialog::DataDialog ( const wxString& title, const wxPoint& pos, 
		   const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
  {
		//Set up the panel
  		wxPanel    *panel = new wxPanel(this, -1);
 
		//Define and position the StaticTexts - ie the labels
		wxStaticText 	*clientIDLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("ID Number"), wxPoint(15, 25) );
		wxStaticText 	*nameLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("First Name"), wxPoint(15, 60) );
		wxStaticText 	*surnameLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Surname"), wxPoint(15, 95) );
 		wxStaticText 	*countryLabel	= new wxStaticText(panel, wxID_ANY, 
 						  wxT("Country"), wxPoint(15, 130) );
 		wxStaticText 	*seasonLabel	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Season"), wxPoint(15, 165) );
 		wxStaticText 	*tripLabel	= new wxStaticText(panel, wxID_ANY, 
 						  wxT("Trip"), wxPoint(300, 15) );
		
		//Define and position the Data Boxes
		ClientIDEditBox = new wxSpinCtrl(panel, -1, wxT("99999"), wxPoint(100, 25), 
					     wxSize(150, -1), wxSP_ARROW_KEYS, 1111, 
					     99999, 1);		
		
		NameEditBox 	=  new wxTextCtrl ( panel, wxID_ANY, wxT("First Name"), 
						    wxPoint(100, 60), wxSize(170, -1) );
		SurnameEditBox 	=  new wxTextCtrl ( panel, wxID_ANY, wxT("Surname"), 
						    wxPoint(100, 95), wxSize(170, -1) );		
        
        CountryEditBox 	=  new wxTextCtrl ( panel, wxID_ANY, wxT("Destination"), 
						    wxPoint(100, 130), wxSize(170, -1) );
			
		
		
		//Define and position a drop-down list for season
        wxArrayString seasons;
		seasons.Add(wxT("Spring"));
		seasons.Add(wxT("Summer"));
		seasons.Add(wxT("Fall"));
		seasons.Add(wxT("Winter"));
		seasonsCombo = new wxComboBox(panel, -1, wxT("Summer"), wxPoint(100, 165), 
					      wxSize(120, -1), seasons, wxCB_READONLY);	
		
		//Define and position the radio buttons for Trip
		internet = new wxRadioButton(panel, -1, wxT("Internet"), wxPoint(300, 45));
		gifted = new wxRadioButton(panel, -1, wxT("Gifted"), wxPoint(300, 65));
		walkin = new wxRadioButton(panel, -1, wxT("Walk-in"),   wxPoint(300, 85));
		telephone = new wxRadioButton(panel, -1, wxT("Telephone"), wxPoint(300, 105));
    
		// Define and position the Response buttons (OK and CANCEL)
		
		// The OK button
		wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), 
					    wxPoint(200, 230), wxDefaultSize, 0);

		// The CANCEL button
		wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
						  wxPoint(330, 230), wxDefaultSize, 0 );
		
  		// Centre the dialog on the parent's window
		Centre();

        	Maximize(); // Maximize the window
		
  }
  



wxString getDataString(Record dataRec)
{
	wxString str = wxT("\n\n");
    
	wxString num;
	num << dataRec.clientID;
	
	str.Append(num);
	str.Append(wxT("\t"));
	str.Append(dataRec.name);
	str.Append(wxT("\t"));
	str.Append(dataRec.surname);
	str.Append(wxT("\t"));
	str.Append(dataRec.country);
	str.Append(wxT("\t"));
    str.Append(dataRec.season);
	str.Append(wxT("\t"));
	str.Append(dataRec.trip);
	str.Append(wxT("\n"));
	
	return str;
}


#endif
