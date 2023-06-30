#include<gtk/gtk.h>

#include"mainWindow.hpp"
#include"Tableau.hpp"

static void draw_tab(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer usrData) {

    int square_size = 40.0;
    int xInit = width/2-19*square_size/2;
    int yInit = height/2-19*square_size/2;

    Tableau tableau;

    cairo_set_source_rgb (cr, 1.0, 1.0, 1.0); /* white */
    cairo_paint (cr);

    for(int j=0; j<19; j++){
        for(int i=0; i<19; i++){

            cairo_set_line_width (cr, 2.0);
            cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
            cairo_rectangle (cr, xInit+i*square_size, yInit+j*square_size, square_size, square_size);
            cairo_stroke_preserve(cr);
            
            if(tableau.giveE(i, j)==1){
                cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
                cairo_fill(cr);
                cairo_stroke_preserve(cr);
            }
            else{
                cairo_stroke(cr);
            }
        }
    }

    tableau.update();
    std::cout<<"bip"<<std::endl;
}

gboolean time_handler(GtkWidget* widget) {
    gtk_widget_queue_draw(widget);
 
    return TRUE;
}

void app_activate(GApplication *app){
    GtkWidget *win;
    GtkWidget *box;
    GtkWidget *btn;
    GtkWidget *area = gtk_drawing_area_new ();
    gpointer init = 0;

    Tableau tableau;

    tableau.perturbation(10,10);
    tableau.perturbation(11,10);
    tableau.perturbation(10,11);
    tableau.perturbation(11,11);
    tableau.perturbation(9,11);
    tableau.perturbation(12,10);

    int width = 800;
    int height = 800;
    
    win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title (GTK_WINDOW (win), "Jeu de la vie");
    gtk_window_set_default_size (GTK_WINDOW (win), width, height);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_set_homogeneous (GTK_BOX (box), TRUE);
    gtk_window_set_child (GTK_WINDOW (win), box);
 
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA (area), draw_tab, NULL, NULL);
    g_timeout_add(1000, (GSourceFunc) time_handler, (gpointer) area);
    //gtk_widget_show(win);
    gtk_window_set_child(GTK_WINDOW (win), area);

    /*
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA (area), propagation, NULL, NULL);
    gtk_window_set_child (GTK_WINDOW (win), area);
    */

    gtk_window_present(GTK_WINDOW(win));
}