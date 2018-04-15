/************************************************************************************
 *  Step 1: Always include the header file wx.h					    
 *************************************************************************************/
#include <wx/wxprec.h>
  
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/aboutdlg.h>
#include <wx/arrstr.h>
#include <wx/textdlg.h>
#include <wx/numdlg.h>

#endif
 
#include <fstream>
#include <string>
#include <sstream>
 
 
using namespace std;
//=====================================================
//    Function to convert an integer to a string     
//=====================================================
string to_string ( int number )
   {
    string number_string = "";
    char charValue;
    int intValue = 0;
    while ( true )
       {
        intValue = number % 10;
        switch ( intValue )
        {
            case 0: charValue = '0'; break;
            case 1: charValue = '1'; break;
            case 2: charValue = '2'; break;
            case 3: charValue = '3'; break;
            case 4: charValue = '4'; break;
            case 5: charValue = '5'; break;
            case 6: charValue = '6'; break;
            case 7: charValue = '7'; break;
            case 8: charValue = '8'; break;
            case 9: charValue = '9'; break;
        }
        number -= intValue;
        number_string = charValue + number_string;
        if ( number == 0 )
           {
            break;
           }
        number = number/10;
       }
    return number_string;
   }
   
//========================================================================
//    Function to create a string with the record data read from the file    
//========================================================================
string makeRecord(int clientID, string firstName, string lastName, string destination, string period, string booking)

    {
       string str = to_string(clientID);
       str.append("\t");
       str.append(firstName);
       str.append("\t");
       str.append(lastName);
       str.append("\t");
       str.append(destination);
       str.append("\t");
       str.append(period);
       str.append("\t");
       str.append(booking);
       str.append("\n");
 
       return str;
    }
    
#include "Queue.h"
#include "Deque.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "BSTree.h"
#include "AVL.h"
#include "Heap.h"
#include "RBT.h"
#include "SplayTree.h"
#include "Set.h"
#include "DataDialog.h"



//Global pointers for the ADT containers
  Deque* dq = new Deque();
  Queue* q = new Queue();
  PriorityQueue* p = new PriorityQueue();
  Stack* s = new Stack();
  BSTree* b = new BSTree();
  AVL* a = new AVL();
  Heap* h = new Heap();
  RBT* r = new RBT();
  SplayTree* splay = new SplayTree();
  Set* setA          = new Set();
  Set* setB          = new Set();
  Set* Inter         = new Set();
  Set* Union         = new Set();
  
 

/************************************************************************************
 *  Step 2: Name an inherited application class from wxApp and declare it with 
 *	  the function to execute the program				    
 *************************************************************************************/
class MyApp: public wxApp
    {
        virtual bool OnInit();
    };



/************************************************************************************
 *   Step 3: Declare the inherited main frame class from wxFrame. In this class 
 *	   also will ALL the events handlers be declared    
 *************************************************************************************/
class MyFrame: public wxFrame
{
    private:
        DECLARE_EVENT_TABLE() //To declare events items
    
    public:
        MyFrame(const wxString& title, const wxPoint& pos, 
                const wxSize& size);
        
        //Functions for File Menu Items
        void OnOpenFile(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);  
        void OnExit(wxCommandEvent& event);     //handle for Quit function
        
        
        
        //Function for Display File Menu Item
        void OnDisplay(wxCommandEvent& event );
        
        
        
        //Functions for Queue Menu Items
        void OnCreateQueue(wxCommandEvent& event);
        void OnAddDataQueue(wxCommandEvent& event);
        void OnDisplayQueue(wxCommandEvent& event);
        void OnShowHeadQueue(wxCommandEvent& event);
        void OnShowTailQueue(wxCommandEvent& event);
        void OnDequeueQueue(wxCommandEvent& event); 
        
          
         //Functions for Deque Menu Items
        void OnCreateDeque(wxCommandEvent& event);
        void OnEnqueueHeadDeque(wxCommandEvent& event);
        void OnEnqueueTailDeque(wxCommandEvent& event);
        void OnDisplayDeque(wxCommandEvent& event);
        void OnShowHeadDeque(wxCommandEvent& event);
        void OnShowTailDeque(wxCommandEvent& event);
        void OnDequeueHeadDeque(wxCommandEvent& event);
        void OnDequeueTailDeque(wxCommandEvent& event);
        
        
        //Functions for Priority Queue Menu Items
        void OnCreatePQ(wxCommandEvent& event);
        void OnAddDataPQ(wxCommandEvent& event);
        void OnDisplayPQ(wxCommandEvent& event);
        void OnShowHeadPQ(wxCommandEvent& event);
        void OnShowTailPQ(wxCommandEvent& event);
        void OnDequeuePQ(wxCommandEvent& event);
        
        
        //Functions for Stack Menu Items
        void OnCreateStack(wxCommandEvent& event);
        void OnPopStack(wxCommandEvent& event);
        void OnPushStack(wxCommandEvent& event);
        void OnDisplayStack(wxCommandEvent& event);
        
        
        //Functions for Binary search Tree Menu Items
        void OnCreateBST(wxCommandEvent& event);
        void OnAddDataBST(wxCommandEvent& event);
        void OnDeleteDataBST(wxCommandEvent& event);
        void OnInorderBST(wxCommandEvent& event);
        void OnPreorderBST(wxCommandEvent& event);
        void OnPostorderBST(wxCommandEvent& event);
        
    
        //Functions for AVL Tree Menu Items
        void OnCreateAVL(wxCommandEvent& event);
        void OnAddDataAVL(wxCommandEvent& event);
        void OnDeleteDataAVL(wxCommandEvent& event);
        void OnInorderAVL(wxCommandEvent& event);
        void OnPreorderAVL(wxCommandEvent& event);
        void OnPostorderAVL(wxCommandEvent& event); 
        
        
        //Functions for Heap Tree Menu Items
        void OnCreateHeap(wxCommandEvent& event);
        void OnAddDataHeap(wxCommandEvent& event);
        void OnDeleteDataHeap(wxCommandEvent& event);
        void OnDisplayHeap(wxCommandEvent& event);
        void OnHeapSort(wxCommandEvent& event); 
        
        
        //Functions for Red-Black Tree Menu Items
        void OnCreateRBT(wxCommandEvent& event);
        void OnAddDataRBT(wxCommandEvent& event);
        void OnDeleteDataRBT(wxCommandEvent& event);
        void OnInorderRBT(wxCommandEvent& event);
        void OnPreorderRBT(wxCommandEvent& event);
        void OnPostorderRBT(wxCommandEvent& event);
        
        
        //Functions for Splay Tree Menu Items
         void OnCreateSplay(wxCommandEvent& event);
         void OnAddDataSplay(wxCommandEvent& event);
        void OnDeleteDataSplay(wxCommandEvent& event);
        void OnInorderSplay(wxCommandEvent& event);
        void OnPreorderSplay(wxCommandEvent& event);
        void OnPostorderSplay(wxCommandEvent& event); 
        
        
        //Functions for Set Menu Items
        void OnCreateSet(wxCommandEvent& event);
        void OnAddDataSet(wxCommandEvent& event);
        void OnDisplaySetA(wxCommandEvent& event);
        void OnDisplaySetB(wxCommandEvent& event);
        void OnIntersection(wxCommandEvent& event);
        void OnDisplayUnion(wxCommandEvent& event);
        void OnDeleteSetA(wxCommandEvent& event);
        void OnDeleteSetB(wxCommandEvent& event);
        
        //Function for Help Menu Item
        void OnAbout(wxCommandEvent& event);
        
        //Public attributes
        wxTextCtrl* MainEditBox;
        wxTextCtrl* filenameTextBox;
        wxString CurrentDocPath;    // The Path to the file we have open
    };



/************************************************************************************
 *  Step 4. Declare the compiler directives				    
 *************************************************************************************/
DECLARE_APP(MyApp)		// Declare Application class
IMPLEMENT_APP(MyApp)		// Create Application class object


enum
        {
            // File menu items
            ID_OpenFile = wxID_HIGHEST + 1,     //File menu item
            ID_Save,
            ID_SaveAs,
            ID_Exit,
            
            //Display menu item
            ID_Display,
            
            // Queue menu items
            ID_CreateQueue,
            ID_AddDataQueue,
            ID_DisplayQueue,
            ID_ShowHeadQueue,
            ID_ShowTailQueue,
            ID_DequeueQueue,
            
            // Deque menu items
            ID_CreateDeque,
            ID_EnqueueHeadDeque,
            ID_EnqueueTailDeque,
            ID_DisplayDeque,
            ID_ShowHeadDeque,
            ID_ShowTailDeque,
            ID_DequeueHeadDeque,
            ID_DequeueTailDeque,
            
            
            // Priority Queue menu items
            ID_CreatePQ,
            ID_AddDataPQ,
            ID_DisplayPQ,
            ID_ShowHeadPQ,
            ID_ShowTailPQ,
            ID_DequeuePQ,
           
             
            // Stack menu items
            ID_CreateStack,
            ID_PopStack,
            ID_PushStack,
            ID_DisplayStack,
            
            
            // BST menu items
            ID_CreateBST,
            ID_AddDataBST,
            ID_DeleteDataBST,
            ID_InorderBST,
            ID_PreorderBST,
            ID_PostorderBST,
            
            
            // AVL Tree menu items 
            ID_CreateAVL,
            ID_AddDataAVL,
            ID_DeleteDataAVL,
            ID_InorderAVL,
            ID_PreorderAVL,
            ID_PostorderAVL,
            
            
            // Heap Tree Menu items
            ID_CreateHeap,
            ID_AddDataHeap,
            ID_DeleteDataHeap,
            ID_DisplayHeap,
            ID_HeapSort,
            
            
            // Red-Black Tree Menu items
            ID_CreateRBT,
            ID_AddDataRBT,
            ID_DeleteDataRBT,
            ID_InorderRBT,
            ID_PreorderRBT,
            ID_PostorderRBT,
            
            
            // Splay Tree menu items
            ID_CreateSplay,
            ID_AddDataSplay,
            ID_DeleteDataSplay,
            ID_InorderSplay,
            ID_PreorderSplay,
            ID_PostorderSplay,
            
            
            // Set items
            ID_CreateSet,
            ID_AddDataSet,
            ID_DisplaySetA,
            ID_DisplaySetB,
            ID_Intersection,
            ID_DisplayUnion,
            ID_DeleteSetA,
            ID_DeleteSetB,
            
            
            // Help menu items
            ID_About,
        };

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
        // Events for the "File" menu items
        EVT_MENU ( ID_OpenFile,   MyFrame::OnOpenFile )       //File Menu
        EVT_MENU ( ID_Save,       MyFrame::OnSave )
        EVT_MENU ( ID_SaveAs,     MyFrame::OnSaveAs )
        EVT_MENU ( ID_Exit,       MyFrame::OnExit )
        
        //Events for the "Display" menu item
        EVT_MENU ( ID_Display,       MyFrame::OnDisplay )
        
        // Events for the "Queue" menu items
        EVT_MENU ( ID_CreateQueue,    MyFrame::OnCreateQueue)
        EVT_MENU ( ID_AddDataQueue,   MyFrame::OnAddDataQueue)
        EVT_MENU ( ID_DisplayQueue,   MyFrame::OnDisplayQueue)
        EVT_MENU ( ID_ShowHeadQueue,  MyFrame::OnShowHeadQueue)
        EVT_MENU ( ID_ShowTailQueue,  MyFrame::OnShowTailQueue)
        EVT_MENU ( ID_DequeueQueue,   MyFrame::OnDequeueQueue)
        
        // Events for the "Deque" menu items
        EVT_MENU ( ID_CreateDeque,        MyFrame::OnCreateDeque)
        EVT_MENU ( ID_EnqueueHeadDeque,   MyFrame::OnEnqueueHeadDeque)
        EVT_MENU ( ID_EnqueueTailDeque,   MyFrame::OnEnqueueTailDeque)
        EVT_MENU ( ID_DisplayDeque,       MyFrame::OnDisplayDeque)
        EVT_MENU ( ID_ShowHeadDeque,      MyFrame::OnShowHeadDeque)
        EVT_MENU ( ID_ShowTailDeque,      MyFrame::OnShowTailDeque)
        EVT_MENU ( ID_DequeueHeadDeque,   MyFrame::OnDequeueHeadDeque)
        EVT_MENU ( ID_DequeueTailDeque,   MyFrame::OnDequeueTailDeque)
      
        // Events for the "Priority Queue" menu items
        EVT_MENU ( ID_CreatePQ,       MyFrame::OnCreatePQ)
        EVT_MENU ( ID_AddDataPQ,      MyFrame::OnAddDataPQ)
        EVT_MENU ( ID_DisplayPQ,      MyFrame::OnDisplayPQ)
        EVT_MENU ( ID_ShowHeadPQ,     MyFrame::OnShowHeadPQ)
        EVT_MENU ( ID_ShowTailPQ,     MyFrame::OnShowTailPQ)
        EVT_MENU ( ID_DequeuePQ,      MyFrame::OnDequeuePQ)
        
        // Events for the "Stack" menu items
        EVT_MENU ( ID_CreateStack,        MyFrame::OnCreateStack)
        EVT_MENU ( ID_PopStack,           MyFrame::OnPushStack)
        EVT_MENU ( ID_PushStack,          MyFrame::OnPushStack)
        EVT_MENU ( ID_DisplayStack,       MyFrame::OnDisplayStack)
    
        // Events for the "BST" menu items
        EVT_MENU ( ID_CreateBST,          MyFrame::OnCreateBST)
        EVT_MENU ( ID_AddDataBST,         MyFrame::OnAddDataBST)
        EVT_MENU ( ID_DeleteDataBST,      MyFrame::OnDeleteDataBST)
        EVT_MENU ( ID_InorderBST,         MyFrame::OnInorderBST)
        EVT_MENU ( ID_PreorderBST,        MyFrame::OnPreorderBST)
        EVT_MENU ( ID_PostorderBST,       MyFrame::OnPostorderBST)
       
        // Events for the "AVL Tree" menu items
        EVT_MENU ( ID_CreateAVL,          MyFrame::OnCreateAVL)
        EVT_MENU ( ID_AddDataAVL,         MyFrame::OnAddDataAVL)
        EVT_MENU ( ID_DeleteDataAVL,      MyFrame::OnDeleteDataAVL)
        EVT_MENU ( ID_InorderAVL,         MyFrame::OnInorderAVL)
        EVT_MENU ( ID_PreorderAVL,        MyFrame::OnPreorderAVL)
        EVT_MENU ( ID_PostorderAVL,       MyFrame::OnPostorderAVL)
        
        // Events for the "Heap" menu items
        EVT_MENU ( ID_CreateHeap,         MyFrame::OnCreateHeap)
        EVT_MENU ( ID_AddDataHeap,        MyFrame::OnAddDataHeap)
        EVT_MENU ( ID_DeleteDataHeap,     MyFrame::OnDeleteDataHeap)
        EVT_MENU ( ID_DisplayHeap,        MyFrame::OnDisplayHeap)
        EVT_MENU ( ID_HeapSort,           MyFrame::OnHeapSort)
        
        // Events for the "Red-Black Tree" menu items
        EVT_MENU ( ID_CreateRBT,          MyFrame::OnCreateRBT)
        EVT_MENU ( ID_AddDataRBT,         MyFrame::OnAddDataRBT)
        EVT_MENU ( ID_DeleteDataRBT,      MyFrame::OnDeleteDataRBT)
        EVT_MENU ( ID_InorderRBT,         MyFrame::OnInorderRBT)
        EVT_MENU ( ID_PreorderRBT,        MyFrame::OnPreorderRBT)
        EVT_MENU ( ID_PostorderRBT,       MyFrame::OnPostorderRBT)
      
        // Events for the "Splay Tree" menu items
        EVT_MENU ( ID_CreateSplay,          MyFrame::OnCreateSplay)
        EVT_MENU ( ID_AddDataSplay,         MyFrame::OnAddDataSplay)
        EVT_MENU ( ID_DeleteDataSplay,      MyFrame::OnDeleteDataSplay)
        EVT_MENU ( ID_InorderSplay,         MyFrame::OnInorderSplay)
        EVT_MENU ( ID_PreorderSplay,        MyFrame::OnPreorderSplay)
        EVT_MENU ( ID_PostorderSplay,       MyFrame::OnPostorderSplay)
       
        // Events for the "Set" menu items
        EVT_MENU ( ID_CreateSet,          MyFrame::OnCreateSet)
        EVT_MENU ( ID_AddDataSet,         MyFrame::OnAddDataSet)
        EVT_MENU ( ID_DisplaySetA,        MyFrame::OnDisplaySetA)
        EVT_MENU ( ID_DisplaySetB,        MyFrame::OnDisplaySetB)
        EVT_MENU ( ID_Intersection,       MyFrame::OnIntersection)
        EVT_MENU ( ID_DisplayUnion,       MyFrame::OnDisplayUnion)
        EVT_MENU ( ID_DeleteSetA,         MyFrame::OnDeleteSetA)
        EVT_MENU ( ID_DeleteSetB,         MyFrame::OnDeleteSetB)
        
        // Events for the "Help" menu items
        EVT_MENU ( ID_About,       	MyFrame::OnAbout)
 
        
END_EVENT_TABLE () 



/************************************************************************************
 *  Step 5.  Define the Application class function to initialize the application
 *************************************************************************************/
bool MyApp::OnInit()
    {
        // Create the main application window
        MyFrame *frame = new MyFrame( wxT("COMP2611 - Pelicans Travel Database"), wxPoint(50,50), 
                                      wxSize(920,600) );
    
        // Display the window
        frame->Show(TRUE);
    
        SetTopWindow(frame);
    
        return TRUE;
    
    }


/************************************************************************************
 *  Step 6:   Define the Constructor functions for the Frame class
 *************************************************************************************/
MyFrame::MyFrame ( const wxString& title, const wxPoint& pos, const wxSize& size) : 
                    wxFrame((wxFrame *)NULL, -1, title, pos, size)
    {
        // Set the frame icon - optional
        SetIcon(wxIcon(wxT("uwiIcon.xpm")));
    
        // Create the main-menu item
        wxMenu *menuFile =        new wxMenu;
        wxMenu *menuDisplay =     new wxMenu;
        wxMenu *menuQueue =       new wxMenu;
        wxMenu *menuPQ    =       new wxMenu;
        wxMenu *menuDeque =       new wxMenu;
        wxMenu *menuStack =       new wxMenu;
        wxMenu *menuBST   =       new wxMenu;
        wxMenu *menuAVL   =       new wxMenu;
        wxMenu *menuHeap  =       new wxMenu;
        wxMenu *menuRBT   =       new wxMenu;
        wxMenu *menuSplay =       new wxMenu;
        wxMenu *menuSet   =       new wxMenu;
        wxMenu *menuHelp =        new wxMenu;
    
        
        
        
        //Create a Main menu bar
        wxMenuBar *menuBar = new wxMenuBar;
       
            //Append the main menu items ("File" and "Help") to it
            menuBar->Append( menuFile, wxT("&File") );
            menuBar->Append( menuDisplay, wxT("&Display File") );
            menuBar->Append( menuQueue,  wxT("Queue") );
            menuBar->Append( menuPQ,     wxT("Priority Queue") );
            menuBar->Append( menuDeque,  wxT("Deque") );
            menuBar->Append( menuStack,  wxT("Stack") );
            menuBar->Append( menuBST,    wxT("BST") );
            menuBar->Append( menuAVL,    wxT("AVL Tree") );
            menuBar->Append( menuHeap,   wxT("Heap") );
            menuBar->Append( menuRBT,    wxT("RB Tree") );
            menuBar->Append( menuSplay,  wxT("Splay") );
            menuBar->Append( menuSet,    wxT("Set") );
            menuBar->Append( menuHelp,   wxT("Help") );
            
            
            //Append the sub-menu items to the File Main Menu item
            menuFile->Append( ID_OpenFile,   wxT("&Open File..."), wxT("Open an Existing file") );
            menuFile->Append( ID_Save,       wxT("&Save"), wxT("Save opened file") );
            menuFile->Append( ID_SaveAs,     wxT("Save &As..."), wxT("Save display as a new file") );
            menuFile->Append( ID_Exit,       wxT("E&xit"), wxT("Close and EXIT Program") );
     
            
            //Append the sub-menu items to the Display File Menu item
            menuDisplay->Append( ID_Display,    wxT("&Display File..."), wxT("Display contents of opened file") );
            
           
    //Append the sub-menu items to the Queue Main Menu item
    menuQueue->Append( ID_CreateQueue,   wxT("Create Queue"), wxT("Create the Queue") );
    menuQueue->Append( ID_AddDataQueue,  wxT("Add Data"),     wxT("Add data to Queue") );
    menuQueue->Append( ID_DisplayQueue,  wxT("Display All"),  wxT("Display ALL records") );
    menuQueue->Append( ID_ShowHeadQueue, wxT("Show Head"),    wxT("Show record at head") );
    menuQueue->Append( ID_ShowTailQueue, wxT("Show Tail"),    wxT("Show record at tail") );
    menuQueue->Append( ID_DequeueQueue,  wxT("Dequeue"),      wxT("Remove record from head") );
            
    
    //Append the sub-menu items to the Deque Main Menu item
    menuDeque->Append( ID_CreateDeque,      wxT("Create Deque"),    wxT("Create the Deque") );    
    menuDeque->Append( ID_EnqueueHeadDeque,     wxT("Add Head"),    wxT("Add record to head") );   
    menuDeque->Append( ID_EnqueueTailDeque,     wxT("Add Tail"),    wxT("Add record to tail") );   
    menuDeque->Append( ID_DisplayDeque,     wxT("Display All"),     wxT("Display ALL records") ); 
    menuDeque->Append( ID_ShowHeadDeque,    wxT("Show Head"),       wxT("Show record at head") ); 
    menuDeque->Append( ID_ShowTailDeque,    wxT("Show Tail"),       wxT("Show record at tail") ); 
    menuDeque->Append( ID_DequeueHeadDeque, wxT("Dequeue Head"),    wxT("Remove record from head") );
    menuDeque->Append( ID_DequeueTailDeque, wxT("Dequeue Tail") ,   wxT("Remove record from tail"));
    
    
    //Append the sub-menu items to the Priority Queue Main Menu item
    menuPQ->Append( ID_CreatePQ,     wxT("Create Priority Queue"),   wxT("Create the Priority Queue") );
    menuPQ->Append( ID_AddDataPQ,    wxT("Add Data"),                wxT("Add data to Priority Queue") );
    menuPQ->Append( ID_DisplayPQ,    wxT("Display All"),             wxT("Display ALL records") );
    menuPQ->Append( ID_ShowHeadPQ,   wxT("Show Head"),               wxT("Show record at head") );
    menuPQ->Append( ID_ShowTailPQ,   wxT("Show Tail"),               wxT("Show record at tail") );
    menuPQ->Append( ID_DequeuePQ,   wxT("Dequeue"),                  wxT("Remove record from head") );
    
    
    //Append the sub-menu items to the Stack Main Menu item
    menuStack->Append( ID_CreateStack,   wxT("Create Stack"),  wxT("Create the Stack") );
    menuStack->Append( ID_PopStack,      wxT("Pop"),           wxT("Pop record at head"));
    menuStack->Append( ID_PushStack,     wxT("Push"),          wxT("Push ALL records") );
    menuStack->Append( ID_DisplayStack,  wxT("Display All"),  wxT("Display the Stack") );
    
    
    //Append the sub-menu items to the BST Main Menu item
    menuBST->Append( ID_CreateBST,     wxT("Create BST"),    wxT("Create BST") );
    menuBST->Append( ID_AddDataBST,    wxT("Add Data"),      wxT("Add data to BST") );
    menuBST->Append( ID_DeleteDataBST, wxT("Delete Data"),   wxT("Delete data from BST") );
    menuBST->Append( ID_InorderBST,    wxT("Inorder"),       wxT("Show ALL records Inorder") );
    menuBST->Append( ID_PreorderBST,   wxT("Preorder"),      wxT("Show ALL records Preorder") );
    menuBST->Append( ID_PostorderBST,  wxT("Postorder"),     wxT("Show ALL records Postorder") );
    
    
    //Append the sub-menu items to the AVL Main Menu item
    menuAVL->Append( ID_CreateAVL,     wxT("Create AVL"),    wxT("Create AVL")  );
    menuAVL->Append( ID_AddDataAVL,    wxT("Add Data") ,  wxT("Add data to AVL"));
    menuAVL->Append( ID_DeleteDataAVL, wxT("Delete Data"),  wxT("Delete data from AVL") );
    menuAVL->Append( ID_InorderAVL,    wxT("Inorder"),       wxT("Show ALL records Inorder") );
    menuAVL->Append( ID_PreorderAVL,   wxT("Preorder"),      wxT("Show ALL records Preorder") );
    menuAVL->Append( ID_PostorderAVL,  wxT("Postorder"),     wxT("Show ALL records Postorder") );
    
    
    //Append the sub-menu items to the BST Main Menu item
    menuHeap->Append( ID_CreateHeap,     wxT("Create Heap"),    wxT("Create Heap") );
    menuHeap->Append( ID_AddDataHeap,    wxT("Add Data"),       wxT("Add data to Heap") );
    menuHeap->Append( ID_DeleteDataHeap, wxT("Delete Data"),    wxT("Delete data from Heap") );
    menuHeap->Append( ID_DisplayHeap,    wxT("Display All"),    wxT("Display Heap") );
    menuHeap->Append( ID_HeapSort,       wxT("Heap Sort"),      wxT("Sort Heap") );
    
    
    //Append the sub-menu items to the RBT Main Menu item
    menuRBT->Append( ID_CreateRBT,       wxT("Create RBT"),    wxT("Create RBT") );
    menuRBT->Append( ID_AddDataRBT,      wxT("Add Data"),      wxT("Add data to RBT") );
    menuRBT->Append( ID_DeleteDataRBT,   wxT("Delete Data"),   wxT("Delete data from RBT") );
    menuRBT->Append( ID_InorderRBT,      wxT("Inorder"),       wxT("Show ALL records Inorder") );
    menuRBT->Append( ID_PreorderRBT,     wxT("Preorder"),      wxT("Show ALL records Preorder") );
    menuRBT->Append( ID_PostorderRBT,    wxT("Postorder"),     wxT("Show ALL records Postorder") );
    
    
    //Append Sub-Menu items to Splay menu
    menuSplay->Append( ID_CreateSplay,     wxT("Create Splay"),    wxT("Create Splay") );
    menuSplay->Append( ID_AddDataSplay,    wxT("Add Data"),        wxT("Add data to Splay") );
    menuSplay->Append( ID_DeleteDataSplay, wxT("Delete Data"),     wxT("Delete data from Splay") );
    menuSplay->Append( ID_InorderSplay,    wxT("Inorder"),         wxT("Show ALL records Inorder") );
    menuSplay->Append( ID_PreorderSplay,   wxT("Preorder"),        wxT("Show ALL records Preorder") );
    menuSplay->Append( ID_PostorderSplay,  wxT("Postorder"),       wxT("Show ALL records Postorder") );
 
    
    //Append Sub-Menu items to Set menu
	menuSet->Append( ID_CreateSet, 	wxT("Create Sets"),            wxT("Create Set") );
	menuSet->Append( ID_AddDataSet, 	wxT("Add Data"),           wxT("Add Data to Sets") );
	menuSet->Append( ID_DisplaySetA, 	wxT("Display SetA"),       wxT("Display SetA") );
	menuSet->Append( ID_DisplaySetB,	wxT("Display SetB") ,      wxT("Display SetB"));
	menuSet->Append( ID_Intersection, wxT("Display Intersection"), wxT("Display Intersection") );
	menuSet->Append( ID_DisplayUnion,		 wxT("Display Union"), wxT("Display Union") );
    menuSet->Append( ID_DeleteSetA, 	wxT("Delete from SetA"),   wxT("Delete from SetA") );
    menuSet->Append( ID_DeleteSetB, 	wxT("Delete from SetB"),   wxT("Delete from SetB") );
    
    
    //Append the sub-menu items to the Help Main Menu item
     menuHelp->Append( ID_About, wxT("About"),  wxT("Display Information") );
        
	
        // ... and now... attach this main menu bar to the frame
        SetMenuBar( menuBar );
    
        // Create a status bar just for fun
        CreateStatusBar(3);
    
        //Put something in the first section of the status bar
        SetStatusText( wxT("Ready...") );
    
        //Put something in the second section of the status bar
        SetStatusText( wxT("Gabriel Phillips"), 1 );
        
        //Put something in the third section of the status bar
        SetStatusText( wxT("412001481"), 2 );
    
    
    
     
     
     
    //Set up the panel for data display
//=========================================================================================
//=========================== DO NOT CHANGE THE CODE IN THIS SECTION ======================
//=========================================================================================
 
    wxPanel     *panel  = new wxPanel(this, -1);
    wxBoxSizer  *vbox   = new wxBoxSizer(wxVERTICAL);       //Vertical sizer for main window
    wxBoxSizer  *hbox1  = new wxBoxSizer(wxHORIZONTAL);     //Horizontal sizer for main window
 
    //Add two textboxes to the panel for data display
    wxBoxSizer  *hbox2  = new wxBoxSizer(wxHORIZONTAL);     //Horizontal sizer for filename window
    wxBoxSizer  *hbox3  = new wxBoxSizer(wxHORIZONTAL);     //Horizontal sizer for display window
     
    wxStaticText    *fileLabel  = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
    wxStaticText    *displayLabel   = new wxStaticText(panel, wxID_ANY, wxT("Display"));
 
    //Initialize the filename textbox window
    filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
     
    //Initialize the display window
    MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
                      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);
                       
 
    //Position the labels and textboxes in the panel
    hbox1->Add(fileLabel, 0, wxRIGHT, 8);
    hbox1->Add(filenameTextBox, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
 
    vbox->Add(-1, 10);
    hbox2->Add(displayLabel, 0);
    vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
    vbox->Add(-1, 10);
 
    hbox3->Add(MainEditBox, 1, wxEXPAND);
    vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
 
    //vbox->Add(-1, 25);
    panel->SetSizer(vbox);
 
    Centre();
     
  }


/************************************************************************************
 *  Step 7:  Define member functions for the Frame class
 *************************************************************************************/
void MyFrame::OnOpenFile(wxCommandEvent& event )
    {
        // Creates a "open file" dialog with 3 file types
        wxFileDialog *OpenDialog = new wxFileDialog( this,
        (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
            (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                 wxFD_OPEN, wxDefaultPosition);
  
        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
        {
                // Sets our current document to the file the user selected
                CurrentDocPath = OpenDialog->GetPath();
 
        //Clean up filename textbox and Display file name in filename textbox
        filenameTextBox->Clear();
        filenameTextBox->AppendText(CurrentDocPath);
 
            MainEditBox->LoadFile(CurrentDocPath);   //Opens that file in the MainEditBox
 
            // Set the Title
            SetTitle(wxString(wxT("COMP2611 - Pelicans Travel Database: 412001481")));
        }
 
    }
  
void MyFrame::OnSave(wxCommandEvent& event )
    {
    // Save to the already-set path for the document
    MainEditBox->SaveFile(CurrentDocPath);
    }
    
void MyFrame::OnSaveAs(wxCommandEvent& event)
    {
    wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                            wxEmptyString, wxEmptyString,
                            (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                            wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
 
    // Creates a Save Dialog with 4 file types
    if (SaveDialog->ShowModal() == wxID_OK)  // If the user clicked "OK"
        {
        CurrentDocPath = SaveDialog->GetPath();
 
        // set the path of our current document to the file the user chose to save under
        MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path
 
        // Set the Title to reflect the file open
        SetTitle(wxString(wxT("COMP2611 - Pelicans Travel Database : 412001481")));
        }
         
    }
   
void MyFrame::OnExit(wxCommandEvent& event)
    {
    wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
    Close(TRUE); // Close the window
    }
 
 

   void MyFrame::OnAbout ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxString msg;
    
        msg.Printf(wxT("Creator: Gabriel Phillips 412001481.  Version: %s"), wxVERSION_STRING);
        
        wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}


    //=======================================================================================
//==================== Definition for the Queue Functions ===============================
//=======================================================================================

void MyFrame::OnDisplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
            // Creates a "open file" dialog with 4 file types
    wxFileDialog *OpenDialog = new wxFileDialog( this, (wxT("Choose a file to open")),
                wxEmptyString, wxEmptyString,
                (wxT("Data files (*.dat)|*.dat|Text Files (*.txt)|*.txt|All files (*.*)|*.*")),
                wxFD_OPEN, wxDefaultPosition);
 
    MainEditBox->Clear();
 
    MainEditBox->LoadFile(CurrentDocPath);
    }
            
            
//=======================================================================================
//==================== Definition for the Queue Functions ===============================
//=======================================================================================

void MyFrame::OnCreateQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Queue
    q->purgeQueue();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Queue
            if (head % 2 == 0)
            {
                q->enqueueTail( clientID, firstName, lastName, destination, period, booking);
            }
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
        
    }
    
void MyFrame::OnAddDataQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
    
    
    struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("Add Data to Queue"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			//Grab value from the first name Box.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the Surname Box
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
		
			//Grab value from the clientID Box
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
			
			// Grab the total number of nights
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
			if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-in");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
	
			//Grab the list item selected
			
			dataRec.season 	   = datadialog->seasonsCombo->GetValue();

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
            
            			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string country    = string(dataRec.country.mb_str());;
			string season   = string(dataRec.season.mb_str());;
			string trip      = string(dataRec.trip.mb_str());;
            
            MainEditBox->AppendText(getDataString(dataRec));
			
			// ... Now send the data to the ADT. e.g
			q -> enqueueTail(clientID, firstName, lastName, country, season, trip);
   }
    
    else {
        datadialog -> Close();

    }
    datadialog -> Destroy();
        
    }

void MyFrame::OnDisplayQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = q->displayAll();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
       MainEditBox->AppendText(wxRecords);     
        
    }
    
void MyFrame::OnShowHeadQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = q->showHeadQueue();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head Of Queue:\n\n"));
       MainEditBox->AppendText(wxRecord);      
        
    }
    
void MyFrame::OnShowTailQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = q->showTailQueue();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord at Tail Of Queue:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
        
    }
    
void MyFrame::OnDequeueQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = q->dequeueHead();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head Of Queue:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
        
    }
    
//=======================================================================================
//==================== Definition for the Deque Functions ===============================
//=======================================================================================

void MyFrame::OnCreateDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Deque
    dq->purgeDeque();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Deque
            if (head % 2 == 0)
                dq->enqueueHead( clientID, firstName, lastName, destination, period, booking);
            else
                dq->enqueueTail( clientID, firstName, lastName, destination, period, booking);
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }

void MyFrame::OnEnqueueHeadDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("Add Data to Deque Head"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			//Grab value from the first name Box.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the Surname Box
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
		
			//Grab value from the clientID Box
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
			
			// Grab the total number of nights
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
			if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-in");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
	
			//Grab the list item selected
			
			dataRec.season 	   = datadialog->seasonsCombo->GetValue();

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
            
            			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string country    = string(dataRec.country.mb_str());;
			string season   = string(dataRec.season.mb_str());;
			string trip      = string(dataRec.trip.mb_str());;
            
            MainEditBox->AppendText(getDataString(dataRec));
			
			// ... Now send the data to the ADT. e.g
			dq -> enqueueHead(clientID, firstName, lastName, country, season, trip);
            }
        else {
        datadialog -> Close();
        
    }
datadialog -> Destroy();

    }

void MyFrame::OnEnqueueTailDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("Add Data to Deque Tail"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			//Grab value from the first name Box.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the Surname Box
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
		
			//Grab value from the clientID Box
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
			
			// Grab the total number of nights
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
			if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-in");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
	
			//Grab the list item selected
			
			dataRec.season 	   = datadialog->seasonsCombo->GetValue();

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
            
            			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string country    = string(dataRec.country.mb_str());;
			string season   = string(dataRec.season.mb_str());;
			string trip      = string(dataRec.trip.mb_str());;
            
            MainEditBox->AppendText(getDataString(dataRec));
			
			// ... Now send the data to the ADT. e.g
			dq -> enqueueTail(clientID, firstName, lastName, country, season, trip);
            }
        else {
        datadialog -> Close();
        
    }
datadialog -> Destroy();
    }

void MyFrame::OnDisplayDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = dq->displayAll();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Deque:\n\n"));
       MainEditBox->AppendText(wxRecords);     
        
        
    }
    
void MyFrame::OnShowHeadDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = dq->showHead();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head Of Deque:\n\n"));
       MainEditBox->AppendText(wxRecord);      
        
    }
    
void MyFrame::OnShowTailDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = dq->showTail();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord at Tail Of Deque:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
        
    }
    
void MyFrame::OnDequeueHeadDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = dq->dequeueHead();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head Of Deque:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
void MyFrame::OnDequeueTailDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = dq->dequeueTail();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Tail Of Deque:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }



//=======================================================================================
//==================== Definition for the Priority Queue Functions ===============================
//=======================================================================================

void MyFrame::OnCreatePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the PQ
    p->purgePQ();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the PQ
            if (head % 2 == 0)
            {
                p->enqueuePQ( clientID, firstName, lastName, destination, period, booking );
            }
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnAddDataPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("Add Data to Priority Queue"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			//Grab value from the first name Box.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the Surname Box
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
		
			//Grab value from the clientID Box
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
			
			// Grab the total number of nights
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
			if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-in");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
	
			//Grab the list item selected
			
			dataRec.season 	   = datadialog->seasonsCombo->GetValue();

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
            
            			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string country    = string(dataRec.country.mb_str());;
			string season   = string(dataRec.season.mb_str());;
			string trip      = string(dataRec.trip.mb_str());;
            
            MainEditBox->AppendText(getDataString(dataRec));
			
			// ... Now send the data to the ADT. e.g
			p -> enqueuePQ(clientID, firstName, lastName, country, season, trip);
   }
    
    else {
        datadialog -> Close();

    }
    datadialog -> Destroy();
        

        
    }

void MyFrame::OnDisplayPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = p->displayAll();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in PQ:\n\n"));
       MainEditBox->AppendText(wxRecords);    
        
    }
    
void MyFrame::OnShowHeadPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = p->showHead();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head Of PQ:\n\n"));
       MainEditBox->AppendText(wxRecord);      
        
    }
    
void MyFrame::OnShowTailPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = p->showTail();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord at Tail Of PQ:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
void MyFrame::OnDequeuePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = p->dequeuePQ();;
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head Of PQ:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
//=======================================================================================
//==================== Definition for the Stack Functions ===============================
//=======================================================================================

void MyFrame::OnCreateStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
    
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Stack
    s->purgeStack();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Stack
            if (period == " Spring")
            {
                s->pushStack( clientID, firstName, lastName, destination, period, booking );
            }
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnPopStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
       
        
       string record = s->popStack();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nPop From Stack:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
void MyFrame::OnPushStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("Stack"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
            //Grab value from the IDNoBox
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
        
			//Grab value from the NameBox.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the SurnameBox
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
			
			// Grab value of the country entered
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
			if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-in");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
	
			//Grab the list item selected
			dataRec.season = datadialog->seasonsCombo->GetValue();
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string destination    = string(dataRec.country.mb_str());;
			string period   = string(dataRec.season.mb_str());;
			string booking      = string(dataRec.trip.mb_str());;
			
			// ... Now send the data to the ADT. e.g
			s->pushStack(clientID, firstName, lastName, destination, period , booking);
   }
        
    }
    
void MyFrame::OnDisplayStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = s->displayStack();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In Stack:\n\n"));
       MainEditBox->AppendText(wxRecords);     
        
    }
    
//=======================================================================================
//==================== Definition for the BSTree Functions ===============================
//=======================================================================================

void MyFrame::OnCreateBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
        
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the BST
    b->purgeBSTree();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Stack
            if (head % 2 == 0)
            {
                b->insert( clientID, firstName, lastName, destination, period, booking);
            }
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnAddDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
void MyFrame::OnDeleteDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }

void MyFrame::OnInorderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = b->inOrder();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In Order:\n\n"));
       MainEditBox->AppendText(wxRecords);     
        
    }
    
void MyFrame::OnPreorderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = b->preOrder();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord In Pre Order:\n\n"));
       MainEditBox->AppendText(wxRecord);  
        
    }
    
void MyFrame::OnPostorderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = b->postOrder();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord In Post Order:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
//=======================================================================================
//==================== Definition for the AVL Functions ===============================
//=======================================================================================

void MyFrame::OnCreateAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the AVL
    a->emptyAVL();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the AVL
            if (period == " Fall")
            {
                a->insertAVLNode( clientID, firstName, lastName, destination, period, booking);
            }
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnAddDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
void MyFrame::OnDeleteDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }
    
void MyFrame::OnInorderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = a->inOrderTraversal();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In Order:\n\n"));
       MainEditBox->AppendText(wxRecords);   
        
    }
    
void MyFrame::OnPreorderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = a->preOrderTraversal();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord Pre Order:\n\n"));
       MainEditBox->AppendText(wxRecord);  
        
    }
    
void MyFrame::OnPostorderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = a->postOrderTraversal();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord Post Order:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
//=======================================================================================
//==================== Definition for the Heap Functions ===============================
//=======================================================================================

void MyFrame::OnCreateHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
        int value;
        int val;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Heap
    h->insertHeap(clientID, firstName, lastName, destination, period, booking);
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Heap
            if (period == " Summer")
            {
                h->insertHeap(clientID, firstName, lastName, destination, period, booking);
            }
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnAddDataHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
void MyFrame::OnDeleteDataHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }
    
void MyFrame::OnDisplayHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = h->displayHeap();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nDisplay Records In Heap:\n\n"));
       MainEditBox->AppendText(wxRecords);  
        
    }
    
void MyFrame::OnHeapSort ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = h->HeapSort();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In Heap Sort:\n\n"));
       MainEditBox->AppendText(wxRecord); 
        
    }
    
//=======================================================================================
//==================== Definition for the RBT Functions ===============================
//=======================================================================================

void MyFrame::OnCreateRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
    string firstName;
    string lastName;
    string destination;
    string period;
    string booking;
    string heading;
    string str;
    int val;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the RBT
    r->emptyRBT();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the RBT
            if (head % 2 == 0)
            {
                r->insertRBT(clientID, firstName, lastName, destination, period, booking);
            }
                     
            str = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(str.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }
        
    }
    
void MyFrame::OnAddDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
void MyFrame::OnDeleteDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }
    
void MyFrame::OnInorderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string records = r->inOrder();
        
       //Convert to a wxString
       wxString wxRecords(records.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In Order:\n\n"));
       MainEditBox->AppendText(wxRecords); 
        
    }
    
void MyFrame::OnPreorderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string str = r->preOrder();
        
       //Convert to a wxString
       wxString wxRecord(str.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord Pre Order:\n\n"));
       MainEditBox->AppendText(wxRecord);  
        
    }
    
void MyFrame::OnPostorderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string str = r->postOrder();
        
       //Convert to a wxString
       wxString wxRecord(str.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecord Post Order:\n\n"));
       MainEditBox->AppendText(wxRecord);
        
    }
    
//=======================================================================================
//==================== Definition for the Splay Functions ===============================
//=======================================================================================

void MyFrame::OnCreateSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string str;
        int key;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Splay
    splay->emptySplay();
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
        head++;
         
        if (!infile.eof())
           {
            // Put the record in the Splay
            if (head % 2 == 0)
            {
                splay->Insert(key);
            }
                     
            str = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(str.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
           }
       }   
        
    }
    
void MyFrame::OnAddDataSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
void MyFrame::OnDeleteDataSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
      
   /* struct record dataRec;
    
    DataDialog *datadialog = new DataDialog( wxT("Delete Splay Tree Record"),
                                   wxPoint(200,200), wxSize(600,600) );
    
    // If the OK button is clicked...
    if (datadialog->ShowModal() == wxID_OK )
    {
        //Grab value from the IDNoBox
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
        
        
        //Clear the main edit box and display the record just grabbed
        mainEditBox->Clear();
        
       MainEditBox->AppendText(getDataString(dataRec));
        
        
			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			
        
        splay->remove(clientID);
    }
    else              //if (dialogBox->ShowModal() == wxID_CANCEL)
        datadialog->Close();
    
    datadialog->Destroy();
    
*/} 
        
    
    
void MyFrame::OnInorderSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the Main Edit box
       MainEditBox->Clear();
        
       string str = splay->InOrder();
        
       //Convert to a wxString
       wxString wxRecords(str.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In InOrder:\n\n"));
       MainEditBox->AppendText(wxRecords);
        
    }
    
void MyFrame::OnPreorderSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
       
    }
    
void MyFrame::OnPostorderSplay ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
        
    }
    
//=======================================================================================
//==================== Definition for the Sets Functions ===============================
//=======================================================================================

void MyFrame::OnCreateSet ( wxCommandEvent& WXUNUSED ( event ) )
    {
        int    clientID;
        string firstName;
        string lastName;
        string destination;
        string period;
        string booking;
        string heading;
        string record;
        int value;
        int val;
     
    int    head = -1;
    char comma;
     
    // Clear the Main Edit box
    MainEditBox->Clear();
 
    //Empty the Heap
    
     
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);
         
    // Check to see if a valid file was opened.
    if (!infile)
       {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
       }
       
      
        
     
    // Read off the heading line
    getline(infile, heading, '\n');
     
        while (!infile.eof())
       {
        infile  >> clientID >> comma;
        getline(infile, firstName, ',');
        getline(infile, lastName, ',');    
        getline(infile, destination, ',');
        getline(infile, period, ',');
        infile >> booking;
            
	   
           if (!infile.eof())
           {
            // Put the record in the Set
            if (destination == " St Lucia " || destination == "Trinidad" || destination == "Jamaica" || destination == "St Vincent" || destination == "Grenada" || destination == "St Kitts" || destination == "Dominica" || destination == "Guyana" || destination == "Antigua" || destination == "Montserrat")
            {
                setA->addElements(clientID, firstName, lastName, destination, period, booking);
            }
            else
            {
                setB->addElements(clientID, firstName, lastName, destination, period, booking);
            }  
         
        
                     
            record = makeRecord(clientID, firstName, lastName, destination, period, booking);
 
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxT("Adding: "));
            MainEditBox->AppendText(wxRecord);
        }
       }   
       
    }
    
void MyFrame::OnAddDataSet ( wxCommandEvent& WXUNUSED ( event ) )
    {
        struct record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Pelicans Travel Database: 412001481"), 
							 wxPoint(200,200), wxSize(700,300) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			//Grab value from the NameBox.
			dataRec.name = datadialog->NameEditBox->GetValue();
			
			//Grab value from the SurnameBox
			dataRec.surname = datadialog->SurnameEditBox->GetValue();
		
			//Grab value from the IDNoBox
			dataRec.clientID = datadialog->ClientIDEditBox->GetValue();
			
			// Grab the total number of nights
			dataRec.country = datadialog->CountryEditBox->GetValue();
			
			
			//Grab the active radio button
			if (datadialog->internet->GetValue() == true) 
			    dataRec.trip = wxT("Internet");
			if (datadialog->gifted->GetValue() == true) 
			    dataRec.trip = wxT("Gifted");
            if (datadialog->walkin->GetValue() == true) 
			    dataRec.trip = wxT("Walk-In");
			if (datadialog->telephone->GetValue() == true) 
			    dataRec.trip = wxT("Telephone");
			
	
			//Grab the list item selected
			dataRec.season = datadialog->seasonsCombo->GetValue();

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			
			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    clientID 	 = dataRec.clientID;
			string firstName = string(dataRec.name.mb_str());
			string lastName  = string(dataRec.surname.mb_str());;
			string country    = string(dataRec.country.mb_str());;
			string season   = string(dataRec.season.mb_str());;
			string trip      = string(dataRec.trip.mb_str());;
            
            MainEditBox->AppendText(getDataString(dataRec));
           

			// ... Now send the data to the ADT. e.g
			setA->addElements(clientID, firstName, lastName, country, season, trip);
   }     
       // else {
           // setB->addElements(clientID, name, surname, destination, period, booking);
//}
        
    }
    
void MyFrame::OnDisplaySetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
       // Clear the edit box
       MainEditBox->Clear();    
        
       string record = setA->displaySet();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In SetA:\n\n"));
       MainEditBox->AppendText(wxRecord);   
        
    }

void MyFrame::OnDisplaySetB ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
       MainEditBox->Clear();    
        
       string record = setB->displaySet();
        
       //Convert to a wxString
       wxString wxRecord(record.c_str(), wxConvUTF8);
        
       //display the words in the MainEditBox
       MainEditBox->AppendText(wxT("\t\t\t\t\nRecords In SetB:\n\n"));
       MainEditBox->AppendText(wxRecord);  
        
    }
    
void MyFrame::OnIntersection ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear();
 
	string str = "Intersection :\n\n";
	Inter->intersection(setA, setB);
		
	str.append(Inter->displaySet());
	
	wxString wxRecString(str.c_str(), wxConvUTF8);

	// Display the wxString in the MainEditBox
	MainEditBox->AppendText(wxRecString);  
        
    }
    
void MyFrame::OnDisplayUnion ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear();
 
	string str = "Union :\n\n";
	Union->unionOfSets(setA, setB);
		
	str.append(Union->displaySet());
	
	// Convert 'strVal' into a wxString for display
	wxString wxRecString(str.c_str(), wxConvUTF8);

	// Display the wxString in the MainEditBox
	MainEditBox->AppendText(wxRecString);    
        
    }
    
void MyFrame::OnDeleteSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }
    
void MyFrame::OnDeleteSetB ( wxCommandEvent& WXUNUSED ( event ) )
    {
        MainEditBox->Clear(); 
        
    }




