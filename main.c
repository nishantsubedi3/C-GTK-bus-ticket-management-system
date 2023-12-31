#include "include/header.h"
#include "include/loginAdminCheck.h"
#include "include/loginAdmin.h"
#include "include/loginUserCheck.h"
#include "include/loginUser.h"
#include "include/registeradmin.h"
#include "include/firstlanding.h"
#include "include/adminpanel.h"
#include "include/userpanel.h"
#include "include/registeruser.h"
#include "include/removeuser.h"
#include "include/listusers.h"
#include "include/landing.h"
#include "include/removebus.h"
#include "include/resetticket.h"
#include "include/bookticket.h"
#include "include/registerbus.h"
#include "include/cancelticket.h"
#include "include/listBookedTicketDetails.h"
int main(int argc, char **argv)
{
    oslist();
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_fullscreen(GTK_WINDOW(window));

    GdkPixbuf *icon_pixbuf = gdk_pixbuf_new_from_file("include/logo.ico", NULL);
    gtk_window_set_icon(GTK_WINDOW(window), icon_pixbuf);

    gtk_widget_show_all(window);
    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", TRUE, NULL);
    if (osname == 3 || osname == 1)
    {
        if (fopen(".files/adminlist", "r") == NULL)
        {
            firstlanding();
        }
        else
        {
            landing();
        }
    }
    gtk_main();
    return 0;
}
