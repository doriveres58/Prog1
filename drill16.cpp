#include "Graph.h"
#include "Lines_window.h"

struct Lines_window : Graph_lib::Window 
{

   Lines_window(Point xy, int w, int h, const string& title);
   
   private:
	   Open_polyline lines;
	   Menu color_menu;
	   Button next_button;
	   Button quit_button;
	   In_box next_x;
	   In_box next_y;
	   Out_box xy_out;
	   Button cmenu_button;
	   Menu style_menu;
	   Button smenu_button;
	  
    void change(Color c) {lines.set_color(c);}
    void style_change(Line_style l) {lines.set_style(l);}

    void show_cmenu();  
    void hide_cmenu();  
    void hide_smenu() {style_menu.hide(); smenu_button.show();}

    void cmenu_pressed() { cmenu_button.hide(); show_cmenu(); }
    void solid_pressed() { style_change(Line_style(Line_style::solid)); hide_smenu(); }
    void dash_pressed() { style_change(Line_style(Line_style::dash)); hide_smenu(); }
    void dot_pressed() { style_change(Line_style(Line_style::dot)); hide_smenu(); }
    void smenu_pressed() { smenu_button.hide(); style_menu.show(); }
    void next();
    void quit();

    static void cb_cmenu(Address,Address);
    static void cb_solid(Address,Address);
    static void cb_dash(Address,Address);
    static void cb_dot(Address,Address);
    static void cb_smenu(Address,Address);
    static void cb_next(Address,Address);
    static void cb_quit(Address,Address);
    static void cb_red(Address,Address);
    static void cb_blue(Address,Address);
    static void cb_black(Address,Address);
	   
    void red_pressed(){change(Color::red);}
    void blue_pressed(){change(Color::blue);}
    void black_pressed(){change(Color::black;}
    void change(Color c) {lines.set_color(c);}
}

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::show_cmenu()
{
    int dy = (color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
    color_menu.show();
}

void Lines_window::hide_cmenu()
{
    color_menu.hide();
    cmenu_button.show();
    int dy = -(color_menu.selection.size()-1)*20;
    smenu_button.move(0,dy);
    for (int i = 0; i<style_menu.selection.size(); ++i)
        style_menu.selection[i].move(0,dy);
    hide_smenu();
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_cmenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).cmenu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_smenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).smenu_pressed();
}

void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}




int main()
{

try
{
   Lines_window win {Point{100,100},600,400,"Lines"};
   return gui_main();
}
catch(std::exception& e)
   {
      std::cerr<<"Exception: "<<e.what()<<'\n';
      return 1;
   }
   catch(...)
   {
      std::cerr<<"unknown exception\n";
      return 2;
   }
}
