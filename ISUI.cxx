#include "ISUI.h"
#include "ISDoc.h"


ISUI::ISUI(){
    Fl::scheme("gtk+");
    fl_register_images();    
    mainWindow = new Fl_Window(600,360);
    menuBar = new Fl_Menu_Bar(0,0,600,20);
    Fl_Menu_Item ISUI::menuitems[]
    {
        {"File",0,0,0,FL_SUBMENU|FL_MENU_DIVIDER},
            {"Open",        FL_CTRL+'o',(Fl_Callback *)ISUI::cb_open,0,0},
            {"Save Contour",FL_CTRL+'c',(Fl_Callback *)ISUI::cb_save_contour,0,0},
            {"Save Mask",   FL_CTRL+'m',(Fl_Callback *)ISUI::cb_save_mask,0,FL_MENU_DIVIDER},
            {"Quit",        FL_CTRL+'q',(Fl_Callback *)ISUI::cb_quit,0,0},
            {0},
        {0},
        {"Edit",0,0,0,FL_MENU_DIVIDER|FL_SUBMENU},
            {"Brush",       FL_CTRL+'b',(Fl_Callback *)ISUI::cb_brush,0,0},
            {"Scissor",     FL_CTRL+'s',(Fl_Callback *)ISUI::cb_scissor,0,0},
            {0},
        {"View",FL_CTRL+'i',0,0,FL_MENU_DIVIDER|FL_SUBMENU},
            {"Blur",        FL_CTRL+'r',0,0,FL_SUBMENU},
                {"3x3",     0,(Fl_Callback *)ISUI::cb_3x3,0,0},
                {"4x4",     0,(Fl_Callback *)ISUI::cb_4x4,0,0},
                {"5x5",     0,(Fl_Callback *)ISUI::cb_5x5,0,0},
                {0},
            {"Zoom in",     FL_CTRL+'+',(Fl_Callback *)ISUI::cb_zoom_in,0,0},
            {"Zoom out",    FL_CTRL+'-',(Fl_Callback *)ISUI::cb_zoom_out,0,0},
            {0},
        {"Help",0,0,0,FL_SUBMENU},
            {"Instructions",FL_CTRL+'i',(Fl_Callback *)ISUI::cb_instruction,0,0},
            {"Project",FL_CTRL+'p',(Fl_Callback *)ISUI::cb_project,0,0},
            {0},
        {0}
    };

    menuBar->copy(menuItems);
//    Fl_Window *imgWindow = new Fl_Window(400,200);
    // Fl_Box box(5,30,280,206);     // widget that will contain image
    // Fl_BMP_Image bmp("ferry.bmp");
    // box.image(bmp);                             // attach jpg image to box

    mainWindow->end();
}

void ISUI::setDocument(ISDoc* doc){
    myDoc = doc;
}
ISDoc* ISUI::getDocument(){
    return myDoc;
}

void ISUI::show(){
    mainWindow->show();
}

/*=======CALL BACK==========*/
void ISUI::cb_open(Fl_Widget *w, void *)
{
    Fl_File_Chooser chooser(".","*",0,"Choose File");
    chooser.show();
    while(chooser.shown())
    {Fl::wait();}
    if(chooser.value()!=NULL)
    {
        ISDoc* newDoc;
        newDoc = this->getDocument();
        route = new char[strlen(chooser.value())+1];
         strcpy(route,chooser.value());
         cout << route << endl;

    }
}

void ISUI::cb_save_contour(Fl_Widget *w, void *){}
void ISUI::cb_save_mask(Fl_Widget *w, void *){}
void ISUI::cb_quit(Fl_Widget *w, void *){}

void ISUI::cb_brush(Fl_Widget *w, void *){}
void ISUI::cb_scissor(Fl_Widget *w, void *){}
void ISUI::cb_3x3(Fl_Widget *w, void *){}
void ISUI::cb_4x4(Fl_Widget *w, void *){}
void ISUI::cb_5x5(Fl_Widget *w, void *){}
    
void ISUI::cb_zoom_in(Fl_Widget *w, void *){}
void ISUI::cb_zoom_out(Fl_Widget *w, void *){}



