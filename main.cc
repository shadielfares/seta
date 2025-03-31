// main.cc
#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
public:
  HelloWorld()
  {
    // Set window properties
    set_title("Hello World");
    set_default_size(300, 200);
    
    // Setup the button
    m_button.set_label("Click me!");
    
    // Set margins individually (more compatible with older gtkmm versions)
    m_button.set_margin_top(50);
    m_button.set_margin_bottom(50);
    m_button.set_margin_start(50);
    m_button.set_margin_end(50);
    
    // When the button is clicked, we will call the on_button_clicked() method
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));
    
    // Add the button to the window
    add(m_button);
    
    // Show all children of the window
    show_all_children();
  }

protected:
  // Signal handler for button click
  void on_button_clicked()
  {
    m_button.set_label("Hello, World!");
  }
  
  // Member widget
  Gtk::Button m_button;
};

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
  HelloWorld window;
  return app->run(window);
}
