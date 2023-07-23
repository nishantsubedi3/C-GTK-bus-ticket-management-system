#include <gtk/gtk.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

int iden;

void registerBus();

void userpannel();

void bookTicket();

void adminpannel();

int loginCheckAdmin();

void clicked();

void listUsers();

void firstlanding();

int registeradmin();

void landing();

int loginCheckUser();

void registerUser();

void removeUser();

int width = 1366, height = 768;

char entered_username[20], entered_password[20];

GtkWidget *window;
GtkWidget *fixed;

void clearmywindow()
{
    GList *children = gtk_container_get_children(GTK_CONTAINER(window));
    GList *node = children;
    while (node != NULL)
    {
        gtk_container_remove(GTK_CONTAINER(window), GTK_WIDGET(node->data));
        node = g_list_next(node);
    }
    g_list_free(children);
}

int osname = 0;

void oslist()
{
#ifdef _WIN32
    osname = 1;
#elif __APPLE__
    osname = 2;
#elif __linux__
    osname = 3;
#elif TARGET_OS_MAC
    osname = 4;
#else
    osname = 5;
#endif
}

void showHF()
{
    GtkWidget *welcometext = gtk_label_new("WELCOME TO TIGER'S BUS TICKET MANAGEMENT SYSTEM!");
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(cssProvider, "label { font-size: 26pt; }", -1, NULL);
    GtkStyleContext *styleContext = gtk_widget_get_style_context(welcometext);
    gtk_style_context_add_provider(styleContext, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    GtkWidget *footer = gtk_label_new("DESIGNED AND CODED BY AADARSHA KHANAL, BIGYAN POKHREL & NISHANT SUBEDI");
    gtk_fixed_put(GTK_FIXED(fixed), welcometext, 155, 1);
    gtk_fixed_put(GTK_FIXED(fixed), footer, (width - 550) / 2, height - 45);
}

void showLE()
{
    GtkWidget *goback = gtk_button_new_with_label("LOG OUT");
    g_signal_connect(goback, "clicked", G_CALLBACK(landing), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), goback, 5, 5);
    GtkWidget *exit = gtk_button_new_with_label("EXIT");
    g_signal_connect(exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), exit, width - 70, 5);
}

void showLEV2(char where[5])
{
    if (strcmp(where, "admin") == 0)
    {
        GtkWidget *goback = gtk_button_new_with_label("GO BACK");
        g_signal_connect(goback, "clicked", G_CALLBACK(adminpannel), NULL);
        gtk_fixed_put(GTK_FIXED(fixed), goback, 5, 5);
        GtkWidget *exit = gtk_button_new_with_label("EXIT");
        g_signal_connect(exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_fixed_put(GTK_FIXED(fixed), exit, width - 70, 5);
    }
    if (strcmp(where, "user") == 0)
    {
        GtkWidget *goback = gtk_button_new_with_label("GO BACK");
        g_signal_connect(goback, "clicked", G_CALLBACK(userpannel), NULL);
        gtk_fixed_put(GTK_FIXED(fixed), goback, 5, 5);
        GtkWidget *exit = gtk_button_new_with_label("EXIT");
        g_signal_connect(exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_fixed_put(GTK_FIXED(fixed), exit, width - 70, 5);
    }
}

gboolean validate_entry_input(GtkEntry *entry, gchar *text, gint length, gint *position, gpointer user_data)
{
    for (gint i = 0; i < length; i++)
    {
        if (!isdigit(text[i]))
        {
            return TRUE;
        }
    }

    return FALSE;
}

void entry_insert_text(GtkEntry *entry, gchar *new_text, gint new_text_length, gint *position, gpointer user_data)
{
    if (validate_entry_input(entry, new_text, new_text_length, position, user_data))
    {
        g_signal_stop_emission_by_name(entry, "insert-text");
    }
}
