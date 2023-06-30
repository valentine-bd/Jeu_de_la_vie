#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include<gtk/gtk.h>
#include"Tableau.hpp"

void app_activate(GApplication *app);
static void draw_tab(GtkDrawingArea *area, cairo_t *cr, int width, int height, Tableau tableau, gpointer usrData);
gboolean time_handler(GtkWidget* widget);
//static void propagation(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer usrData);


#endif //MAIN_WINDOW_HPP