void bus_register()
{
    
}

void registerBus()
{
    clearmywindow();
    g_signal_connect(GTK_WINDOW(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    gtk_window_fullscreen(GTK_WINDOW(window));

    GtkWidget *registrationsuccess = gtk_label_new(NULL);
    gtk_fixed_put(GTK_FIXED(fixed), registrationsuccess, (width - 200) / 2, height - 300);

    GtkWidget *busname_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(busname_entry), "BUS NAME");
    gtk_widget_set_size_request(busname_entry, 200, 50);
    gtk_fixed_put(GTK_FIXED(fixed), busname_entry, (width - 200) / 2, (height - 50) / 2 - 50);

    GtkWidget *total_seat_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(total_seat_entry), "TOTAL NUMBER OF SEATS");
    gtk_entry_set_max_length(GTK_ENTRY(total_seat_entry), 2);
    g_signal_connect(total_seat_entry, "insert-text", G_CALLBACK(entry_insert_text), NULL);
    gtk_widget_set_size_request(total_seat_entry, 200, 50);
    gtk_fixed_put(GTK_FIXED(fixed), total_seat_entry, (width - 200) / 2, (height - 50) / 2);

    GtkWidget *button_register_bus = gtk_button_new_with_label("Register Bus");
    gtk_widget_set_size_request(button_register_bus, 200, 50);
    gtk_fixed_put(GTK_FIXED(fixed), button_register_bus, (width - 200) / 2, (height - 50) / 2 + 50);

    g_object_set_data(G_OBJECT(button_register_bus), "busname_entry", busname_entry);
    g_object_set_data(G_OBJECT(button_register_bus), "total_seat_entry", total_seat_entry);
    g_object_set_data(G_OBJECT(button_register_bus), "registrationsuccess", registrationsuccess);
    g_signal_connect(button_register_bus, "clicked", G_CALLBACK(bus_register), NULL);

    GtkWidget *goback = gtk_button_new_with_label("GO BACK");
    g_signal_connect(goback, "clicked", G_CALLBACK(adminpannel), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), goback, 5, 5);
    GtkWidget *exit = gtk_button_new_with_label("EXIT");
    g_signal_connect(exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), exit, width - 70, 5);

    // header and footer text
    showHF();

    GtkWidget *request2 = gtk_label_new("PLEASE ENTER THE NEW BUS INFO");
    GtkCssProvider *cssProvider2 = gtk_css_provider_new();
    gtk_css_provider_load_from_data(cssProvider2, "label { font-size: 20pt; }", -1, NULL);
    GtkStyleContext *styleContext2 = gtk_widget_get_style_context(request2);
    gtk_style_context_add_provider(styleContext2, GTK_STYLE_PROVIDER(cssProvider2), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_fixed_put(GTK_FIXED(fixed), request2, (width - 400) / 2, 200);

    gtk_widget_show_all(window);
}