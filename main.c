//gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`

#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>

GtkWidget *about_dialog;

void addlink(GtkWidget widget, gpointer window);
void about(GtkWidget widget, gpointer window);

int main(int argc, char *argv[]){
	GtkWidget *window, *fixed, *image ;
	GtkWidget *btn1, *btn2, *btn3, *btn4, *btn5, *btn6;

	gtk_init(&argc, &argv) ;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "HCT Dictionnary");
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	image = gtk_image_new_from_file("thaylinhdz.jpg");
	gtk_container_add(GTK_CONTAINER(fixed), image);
	
	btn1 = gtk_button_new_with_label("Tra từ");
	gtk_fixed_put(GTK_FIXED(fixed), btn1 , 20, 50);
	gtk_widget_set_size_request(btn1, 120, 50);
	//gtk_widget_set_tooltip_text(btn1, "Search a word");
	//g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK(tra_tu), NULL);
	btn2 = gtk_button_new_with_label("Thêm từ");
	gtk_fixed_put(GTK_FIXED(fixed), btn2 , 20, 100);
	gtk_widget_set_size_request(btn2, 120, 50);
//	gtk_widget_set_tooltip_text(btn1, "Search a word");
	//g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK(tra_tu), NULL);
	btn3 = gtk_button_new_with_label("Xóa từ");
	gtk_fixed_put(GTK_FIXED(fixed), btn3 , 20, 150);
	gtk_widget_set_size_request(btn3, 120, 50);
	//gtk_widget_set_tooltip_text(btn1, "Search a word");
//	g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK(tra_tu), NULL);
	btn4 = gtk_button_new_with_label("Thông tin");
	gtk_fixed_put(GTK_FIXED(fixed), btn4, 520 , 70);
	gtk_widget_set_size_request(btn4, 120, 50);
	gtk_widget_set_tooltip_text(btn4, "About");
	g_signal_connect(G_OBJECT(btn4), "clicked", G_CALLBACK(about), NULL);

	btn5 = gtk_button_new_with_label("Thoát");
	gtk_fixed_put(GTK_FIXED(fixed), btn5 , 520, 150);
	gtk_widget_set_size_request(btn5, 120, 50);
	gtk_widget_set_tooltip_text(btn5, "Exit");
	g_signal_connect(G_OBJECT(btn5), "clicked", G_CALLBACK(gtk_main_quit), NULL);

	btn6 = gtk_button_new_with_label("See more about Thay Linh Đẹp zai ngầu lòi vô đối");
	gtk_fixed_put(GTK_FIXED(fixed), btn6 , 200, 580);
	gtk_widget_set_size_request(btn6, 230, 50);
	gtk_widget_set_tooltip_text(btn6, "Link to website");
	g_signal_connect(G_OBJECT(btn6), "clicked", G_CALLBACK(addlink), NULL);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
		gtk_widget_show_all(window);
		gtk_main();



		return 0;
}

void about(GtkWidget widget, gpointer window){
	about_dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about_dialog), "HCT Dictionary");
		gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about_dialog), "Nguyễn Thị Hải Thanh\t20176871\nĐặng Linh Chi\t20176700\nPhạm Minh Hiếu\txxxxxxxx\n");
		gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(about_dialog), "Nhóm 48 - Học sinh ThS Ngô Văn Linh");
		gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(about_dialog), NULL);
		gtk_dialog_run(GTK_DIALOG(about_dialog));
		gtk_widget_destroy(about_dialog);

}

void addlink(GtkWidget widget, gpointer window)
{
	system("xdg-open http://is.hust.edu.vn/~linhnv/");
}