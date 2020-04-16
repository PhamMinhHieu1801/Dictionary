#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	GtkWidget *window, *fixed, *image ;
	GtkWidget *btn1, *btn2, *btn3, *btn4, *btn5, *btn6;
	gtk_init(&argc, &argv) ;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Tìm kiếm");
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	/*image = gtk_image_new_from_file("thaylinhdz.jpg");
	gtk_container_add(GTK_CONTAINER(fixed), image);
	*/
	
	btn1 = gtk_button_new_with_label("Tim kiem");
	gtk_fixed_put(GTK_FIXED(fixed), btn1 , 540, 30);
	gtk_widget_set_size_request(btn1, 30, 30);
	//gtk_widget_set_tooltip_text(btn1, "Search a word");
	//g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK(tra_tu), NULL);
		g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
		gtk_widget_show_all(window);
		gtk_main();



		return 0;
}