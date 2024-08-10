#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int contains_uppercase(const char *password);
int contains_lowercase(const char *password);
int contains_digit(const char *password);
int contains_special(const char *password);
void check_password_strength(GtkWidget *widget, gpointer data);
void toggle_password_visibility(GtkWidget *widget, gpointer entry);
void update_password_strength(GtkEntry *entry, gpointer label);
void apply_css(GtkWidget *widget, const char *css_file);

// Function to check if the password contains an uppercase letter
int contains_uppercase(const char *password) {
    while (*password) {
        if (isupper(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check if the password contains a lowercase letter
int contains_lowercase(const char *password) {
    while (*password) {
        if (islower(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check if the password contains a digit
int contains_digit(const char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check if the password contains a special character
int contains_special(const char *password) {
    const char *special_characters = "!@#$%^&*()-_=+[]{}\\|;:'\",.<>?/`~";
    while (*password) {
        if (strchr(special_characters, *password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check the strength of the password
void check_password_strength(GtkWidget *widget, gpointer data) {
    GtkWidget *entry = ((GtkWidget **)data)[0];
    GtkWidget *label = ((GtkWidget **)data)[1];

    const char *password = gtk_entry_get_text(GTK_ENTRY(entry));
    int length = strlen(password);
    int has_uppercase = contains_uppercase(password);
    int has_lowercase = contains_lowercase(password);
    int has_digit = contains_digit(password);
    int has_special = contains_special(password);

    GString *strength_message = g_string_new(NULL);
    if (length >= 8 && has_uppercase && has_lowercase && has_digit && has_special) {
        g_string_assign(strength_message, "Password is strong.");
    } else {
        g_string_assign(strength_message, "Password is weak. Suggestions:\n");
        if (length < 8) {
            g_string_append(strength_message, "- Make it at least 8 characters long.\n");
        }
        if (!has_uppercase) {
            g_string_append(strength_message, "- Add at least one uppercase letter.\n");
        }
        if (!has_lowercase) {
            g_string_append(strength_message, "- Add at least one lowercase letter.\n");
        }
        if (!has_digit) {
            g_string_append(strength_message, "- Add at least one digit.\n");
        }
        if (!has_special) {
            g_string_append(strength_message, "- Add at least one special character.\n");
        }
    }

    gtk_label_set_text(GTK_LABEL(label), strength_message->str);
    g_string_free(strength_message, TRUE);
}

// Function to toggle password visibility
void toggle_password_visibility(GtkWidget *widget, gpointer entry) {
    gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
    gtk_entry_set_visibility(GTK_ENTRY(entry), active);
}

// Function to update password strength dynamically
void update_password_strength(GtkEntry *entry, gpointer label) {
    const char *password = gtk_entry_get_text(entry);
    int length = strlen(password);
    int has_uppercase = contains_uppercase(password);
    int has_lowercase = contains_lowercase(password);
    int has_digit = contains_digit(password);
    int has_special = contains_special(password);

    GString *strength_message = g_string_new(NULL);
    if (length >= 8 && has_uppercase && has_lowercase && has_digit && has_special) {
        g_string_assign(strength_message, "Strong");
    } else if (length >= 6) {
        g_string_assign(strength_message, "Medium");
    } else {
        g_string_assign(strength_message, "Weak");
    }

    gtk_label_set_text(GTK_LABEL(label), strength_message->str);
    g_string_free(strength_message, TRUE);
}

// Function to apply CSS
void apply_css(GtkWidget *widget, const char *css_file) {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, css_file, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *entry;
    GtkWidget *button;
    GtkWidget *toggle_visibility;
    GtkWidget *strength_label;
    GtkWidget *result_label;
    GtkWidget *container[2];
    GtkWidget *vbox;
    GtkWidget *frame;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Password Strength Checker");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Apply CSS
    apply_css(window, "style.css");

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(vbox), TRUE);
    gtk_widget_set_halign(vbox, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(vbox, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    frame = gtk_frame_new(NULL);
    gtk_widget_set_name(frame, "container"); // Set the name for CSS
    gtk_container_add(GTK_CONTAINER(vbox), frame);

    grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(frame), grid);

    entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE); // Hide the input for password
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 2, 1);

    toggle_visibility = gtk_check_button_new_with_label("Show Password");
    g_signal_connect(toggle_visibility, "toggled", G_CALLBACK(toggle_password_visibility), entry);
    gtk_grid_attach(GTK_GRID(grid), toggle_visibility, 0, 1, 2, 1);

    strength_label = gtk_label_new("Strength: ");
    gtk_grid_attach(GTK_GRID(grid), strength_label, 0, 2, 2, 1);

    result_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 3, 2, 1);

    container[0] = entry;
    container[1] = result_label;

    button = gtk_button_new_with_label("Check Password");
    g_signal_connect(button, "clicked", G_CALLBACK(check_password_strength), container);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);

    g_signal_connect(entry, "changed", G_CALLBACK(update_password_strength), strength_label);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
