#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // For time_t, struct tm, localtime, strftime, mktime, difftime

#define MAX_ADMINS 5
#define MAX_VEHICLES 50
#define MAX_CUSTOMERS 50
#define MAX_SLOTS 50

// Global variables for configuration
double HOURLY_RATE = 20.0; // Default hourly rate

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char password[20];
} Admin;

typedef struct {
    char license_plate[20];
    char vehicle_type[20];
    char entry_time[30];
    char exit_time[30];
    double parking_fee;
    int slot_number;
} Vehicle;

typedef struct {
    char name[50];
    char phone[11];
    char email[50];
    char license_plate[20];
} Customer;

Admin admins[MAX_ADMINS];
int admin_count = 0;
Vehicle parked_vehicles[MAX_VEHICLES];
int parked_vehicle_count = 0;
Customer customers[MAX_CUSTOMERS];
int customer_count = 0;
int parking_slots[MAX_SLOTS]; // 0 for empty, 1 for occupied

double total_revenue = 0.0;

// Function prototypes
void save_data();
void load_data();
void get_current_time(char *buffer);
void display_main_menu();
void admin_registration();
int admin_login();
void admin_panel_menu();
void display_admin_details();
void configure_parking_rates();
void daily_revenue_summary();
void vehicle_panel_menu();
void record_vehicle_entry();
void record_vehicle_exit();
void list_parked_vehicles();
void customer_info_menu();
void add_customer_details();
void view_all_customers();
void search_customer_by_license_plate();
void slot_management_menu();
void display_parking_status();
void display_total_empty_slots();
void clear_input_buffer(); // New utility function

// --- Data Persistence Functions ---
void save_data() {
    FILE *fp = fopen("parking_data.dat", "wb");
    if (fp == NULL) {
        perror("Error opening data file for writing"); // Use perror for detailed error
        return;
    }
    fwrite(&admin_count, sizeof(int), 1, fp);
    fwrite(admins, sizeof(Admin), admin_count, fp);
    fwrite(&parked_vehicle_count, sizeof(int), 1, fp);
    fwrite(parked_vehicles, sizeof(Vehicle), parked_vehicle_count, fp);
    fwrite(&customer_count, sizeof(int), 1, fp);
    fwrite(customers, sizeof(Customer), customer_count, fp);
    fwrite(parking_slots, sizeof(int), MAX_SLOTS, fp);
    fwrite(&HOURLY_RATE, sizeof(double), 1, fp);
    fwrite(&total_revenue, sizeof(double), 1, fp);
    fclose(fp);
}

void load_data() {
    FILE *fp = fopen("parking_data.dat", "rb");
    if (fp == NULL) {
        printf("No existing data found. Starting fresh.\n");
        return;
    }
    fread(&admin_count, sizeof(int), 1, fp);
    fread(admins, sizeof(Admin), admin_count, fp);
    fread(&parked_vehicle_count, sizeof(int), 1, fp);
    fread(parked_vehicles, sizeof(Vehicle), parked_vehicle_count, fp);
    fread(&customer_count, sizeof(int), 1, fp);
    fread(customers, sizeof(Customer), customer_count, fp);
    fread(parking_slots, sizeof(int), MAX_SLOTS, fp);
    fread(&HOURLY_RATE, sizeof(double), 1, fp);
    fread(&total_revenue, sizeof(double), 1, fp);
    fclose(fp);
}

// --- Utility Functions ---
void get_current_time(char *buffer) {
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", info);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Menu Display Functions ---
void display_main_menu() {
    printf("\n--- Parking Lot Management System ---\n");
    printf("1. Admin Registration\n");
    printf("2. Admin Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// --- Admin Management Functions ---
void admin_registration() {
    if (admin_count >= MAX_ADMINS) {
        printf("Maximum number of admins reached.\n");
        return;
    }
    printf("\n--- Admin Registration ---\n");
    printf("Enter Name: ");
    scanf(" %49[^\n]", admins[admin_count].name);
    clear_input_buffer();
    printf("Enter Phone Number: ");
    scanf(" %14[^\n]", admins[admin_count].phone);
    clear_input_buffer();
    printf("Enter Email: ");
    scanf(" %49[^\n]", admins[admin_count].email);
    clear_input_buffer();
    printf("Enter Password: ");
    scanf(" %19[^\n]", admins[admin_count].password);
    clear_input_buffer();
    admin_count++;
    save_data();
    printf("Admin registered successfully!\n");
}

int admin_login() {
    char email[50];
    char password[20];
    printf("\n--- Admin Login ---\n");
    printf("Enter Email: ");
    scanf(" %49[^\n]", email);
    clear_input_buffer();
    printf("Enter Password: ");
    scanf(" %19[^\n]", password);
    clear_input_buffer();

    for (int i = 0; i < admin_count; i++) {
        if (strcmp(admins[i].email, email) == 0 && strcmp(admins[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    printf("Invalid email or password.\n");
    return 0;
}

void admin_panel_menu() {
    int choice;
    do {
        printf("\n--- Admin Panel ---\n");
        printf("1. Admin Details\n");
        printf("2. Configure Parking Rates\n");
        printf("3. Daily Revenue Summary\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                display_admin_details();
                break;
            case 2:
                configure_parking_rates();
                break;
            case 3:
                daily_revenue_summary();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void display_admin_details() {
    printf("\n--- Admin Details ---\n");
    if (admin_count == 0) {
        printf("No admin registered.\n");
        return;
    }
    for (int i = 0; i < admin_count; i++) {
        printf("Admin %d:\n", i + 1);
        printf("  Name: %s\n", admins[i].name);
        printf("  Phone: %s\n", admins[i].phone);
        printf("  Email: %s\n", admins[i].email);
    }
}

void configure_parking_rates() {
    printf("\n--- Configure Parking Rates ---\n");
    printf("Current hourly rate: %.2f BDT\n", HOURLY_RATE);
    printf("Enter new hourly rate: ");
    scanf("%lf", &HOURLY_RATE);
    clear_input_buffer();
    save_data();
    printf("Parking rate updated successfully!\n");
}

void daily_revenue_summary() {
    printf("\n--- Daily Revenue Summary ---\n");
    printf("Total revenue collected: %.2f BDT\n", total_revenue);
}

// --- Vehicle Management Functions ---
void vehicle_panel_menu() {
    int choice;
    do {
        printf("\n--- Vehicle Panel ---\n");
        printf("1. Record Vehicle Entry\n");
        printf("2. Record Vehicle Exit\n");
        printf("3. List Parked Vehicles\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                record_vehicle_entry();
                break;
            case 2:
                record_vehicle_exit();
                break;
            case 3:
                list_parked_vehicles();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void record_vehicle_entry() {
    if (parked_vehicle_count >= MAX_VEHICLES) {
        printf("Parking lot is full.\n");
        return;
    }

    int slot_found = -1;
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parking_slots[i] == 0) {
            slot_found = i;
            break;
        }
    }

    if (slot_found == -1) {
        printf("No empty slots available.\n");
        return;
    }

    printf("\n--- Record Vehicle Entry ---\n");
    printf("Enter License Plate: ");
    scanf(" %19[^\n]", parked_vehicles[parked_vehicle_count].license_plate);
    clear_input_buffer();
    printf("Enter Vehicle Type (Car/Motorcycle/Truck): ");
    scanf(" %19[^\n]", parked_vehicles[parked_vehicle_count].vehicle_type);
    clear_input_buffer();

    get_current_time(parked_vehicles[parked_vehicle_count].entry_time);
    parked_vehicles[parked_vehicle_count].parking_fee = 0.0;
    parked_vehicles[parked_vehicle_count].slot_number = slot_found + 1;
    parking_slots[slot_found] = 1;

    parked_vehicle_count++;
    save_data();
    printf("Vehicle entered successfully. Assigned slot: %d\n", slot_found + 1);
}

void record_vehicle_exit() {
    char license_plate[20];
    printf("\n--- Record Vehicle Exit ---\n");
    printf("Enter License Plate of vehicle to exit: ");
    scanf(" %19[^\n]", license_plate);
    clear_input_buffer();

    int found_index = -1;
    for (int i = 0; i < parked_vehicle_count; i++) {
        if (strcmp(parked_vehicles[i].license_plate, license_plate) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        get_current_time(parked_vehicles[found_index].exit_time);

        struct tm entry_tm, exit_tm;
        time_t entry_raw, exit_raw;

        // Parse entry time
        int year, month, day, hour, minute, second;
        sscanf(parked_vehicles[found_index].entry_time, "%d-%d-%d %d:%d:%d",
               &year, &month, &day, &hour, &minute, &second);
        entry_tm.tm_year = year - 1900;
        entry_tm.tm_mon = month - 1;
        entry_tm.tm_mday = day;
        entry_tm.tm_hour = hour;
        entry_tm.tm_min = minute;
        entry_tm.tm_sec = second;
        entry_tm.tm_isdst = -1; // Let mktime determine DST

        // Parse exit time
        sscanf(parked_vehicles[found_index].exit_time, "%d-%d-%d %d:%d:%d",
               &year, &month, &day, &hour, &minute, &second);
        exit_tm.tm_year = year - 1900;
        exit_tm.tm_mon = month - 1;
        exit_tm.tm_mday = day;
        exit_tm.tm_hour = hour;
        exit_tm.tm_min = minute;
        exit_tm.tm_sec = second;
        exit_tm.tm_isdst = -1; // Let mktime determine DST

        entry_raw = mktime(&entry_tm);
        exit_raw = mktime(&exit_tm);

        if (entry_raw == (time_t)-1 || exit_raw == (time_t)-1) {
            printf("Error converting time. Cannot calculate parking fee.\n");
            // Still proceed to clear slot and remove vehicle
            parking_slots[parked_vehicles[found_index].slot_number - 1] = 0;
            for (int i = found_index; i < parked_vehicle_count - 1; i++) {
                parked_vehicles[i] = parked_vehicles[i + 1];
            }
            parked_vehicle_count--;
            save_data();
            return;
        }

        double diff_seconds = difftime(exit_raw, entry_raw);
        double parked_hours = diff_seconds / 3600.0;
        if (parked_hours < 0) parked_hours = 0; // Should not happen with proper time, but as a safeguard

        parked_vehicles[found_index].parking_fee = parked_hours * HOURLY_RATE;
        total_revenue += parked_vehicles[found_index].parking_fee;

        printf("Vehicle exited successfully.\n");
        printf("License Plate: %s\n", parked_vehicles[found_index].license_plate);
        printf("Entry Time: %s\n", parked_vehicles[found_index].entry_time);
        printf("Exit Time: %s\n", parked_vehicles[found_index].exit_time);
        printf("Parking Duration: %.2f hours\n", parked_hours);
        printf("Parking Fee: %.2f BDT\n", parked_vehicles[found_index].parking_fee);

        parking_slots[parked_vehicles[found_index].slot_number - 1] = 0;

        // Remove vehicle from parked list (shift elements)
        for (int i = found_index; i < parked_vehicle_count - 1; i++) {
            parked_vehicles[i] = parked_vehicles[i + 1];
        }
        parked_vehicle_count--;
        save_data();
    } else {
        printf("Vehicle with license plate '%s' not found.\n", license_plate);
    }
}

void list_parked_vehicles() {
    printf("\n--- List of Parked Vehicles ---\n");
    if (parked_vehicle_count == 0) {
        printf("No vehicles currently parked.\n");
        return;
    }
    printf("%-15s %-15s %-25s %-10s\n", "License Plate", "Vehicle Type", "Entry Time", "Slot");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < parked_vehicle_count; i++) {
        printf("%-15s %-15s %-25s %-10d\n",
               parked_vehicles[i].license_plate,
               parked_vehicles[i].vehicle_type,
               parked_vehicles[i].entry_time,
               parked_vehicles[i].slot_number);
    }
}

// --- Customer Information Functions ---
void customer_info_menu() {
    int choice;
    do {
        printf("\n--- Customer Information ---\n");
        printf("1. Add Customer Details\n");
        printf("2. View All Customers\n");
        printf("3. Search Customer by License Plate\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_customer_details();
                break;
            case 2:
                view_all_customers();
                break;
            case 3:
                search_customer_by_license_plate();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void add_customer_details() {
    if (customer_count >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached.\n");
        return;
    }
    printf("\n--- Add Customer Details ---\n");
    printf("Enter Customer Name: ");
    scanf(" %49[^\n]", customers[customer_count].name);
    clear_input_buffer();
    printf("Enter Customer Phone Number: ");
    scanf(" %14[^\n]", customers[customer_count].phone);
    clear_input_buffer();
    printf("Enter Customer Email: ");
    scanf(" %49[^\n]", customers[customer_count].email);
    clear_input_buffer();
    printf("Enter Vehicle License Plate: ");
    scanf(" %19[^\n]", customers[customer_count].license_plate);
    clear_input_buffer();
    customer_count++;
    save_data();
    printf("Customer details added successfully!\n");
}

void view_all_customers() {
    printf("\n--- All Customer Details ---\n");
    if (customer_count == 0) {
        printf("No customer details available.\n");
        return;
    }
    printf("%-20s %-15s %-25s %-15s\n", "Name", "Phone", "Email", "License Plate");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < customer_count; i++) {
        printf("%-20s %-15s %-25s %-15s\n",
               customers[i].name,
               customers[i].phone,
               customers[i].email,
               customers[i].license_plate);
    }
}

void search_customer_by_license_plate() {
    char license_plate[20];
    printf("\n--- Search Customer by License Plate ---\n");
    printf("Enter License Plate to search: ");
    scanf(" %19[^\n]", license_plate);
    clear_input_buffer();

    int found = 0;
    for (int i = 0; i < customer_count; i++) {
        if (strcmp(customers[i].license_plate, license_plate) == 0) {
            printf("\nCustomer Found:\n");
            printf("  Name: %s\n", customers[i].name);
            printf("  Phone: %s\n", customers[i].phone);
            printf("  Email: %s\n", customers[i].email);
            printf("  License Plate: %s\n", customers[i].license_plate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No customer found with license plate '%s'.\n", license_plate);
    }
}

// --- Slot Management Functions ---
void slot_management_menu() {
    int choice;
    do {
        printf("\n--- Slot Management ---\n");
        printf("1. Display Parking Status\n");
        printf("2. Display Total Empty Slots\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                display_parking_status();
                break;
            case 2:
                display_total_empty_slots();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void display_parking_status() {
    printf("\n--- Parking Slot Status ---\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("Slot %d: %s\n", i + 1, (parking_slots[i] == 1) ? "Occupied" : "Empty");
    }
}

void display_total_empty_slots() {
    int empty_slots = 0;
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parking_slots[i] == 0) {
            empty_slots++;
        }
    }
    printf("\n--- Total Empty Slots ---\n");
    printf("Number of empty parking slots: %d\n", empty_slots);
}

int main() {
    load_data();
    int choice;
    int logged_in = 0;

    while (1) { // Use an infinite loop and break when exiting
        if (!logged_in) {
            display_main_menu();
            scanf("%d", &choice);
            clear_input_buffer(); // Consume the newline

            switch (choice) {
                case 1:
                    admin_registration();
                    break;
                case 2:
                    logged_in = admin_login();
                    break;
                case 3:
                    printf("Exiting program. Goodbye!\n");
                    save_data(); // Save data before exiting
                    return 0; // Exit the program
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else {
            printf("\n--- Admin Menu ---\n");
            printf("1. Admin Panel\n");
            printf("2. Vehicle Panel\n");
            printf("3. Customer Information\n");
            printf("4. Slot Management\n");
            printf("5. Total Revenue\n");
            printf("6. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            clear_input_buffer(); // Consume the newline

            switch (choice) {
                case 1:
                    admin_panel_menu();
                    break;
                case 2:
                    vehicle_panel_menu();
                    break;
                case 3:
                    customer_info_menu();
                    break;
                case 4:
                    slot_management_menu();
                    break;
                case 5:
                    printf("\n--- Total Revenue ---\n");
                    printf("Overall total revenue: %.2f BDT\n", total_revenue);
                    break;
                case 6:
                    logged_in = 0;
                    printf("Logged out successfully.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0; // Should be unreachable with the return 0 in case 3 of main menu
}