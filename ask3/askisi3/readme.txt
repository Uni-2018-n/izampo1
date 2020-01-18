Αντωνης Καλαμακης SDI1800056

compile: g++ -std=c++11 -o main main.cpp classes.cpp


για λόγους δοκιμών και ευκολία ανάγνωσης του output χρησιμοποιώ την DEBUG για να εμφανίζω ή όχι
τα μηνύματα των constructor


Για την class Object:
προστέθηκε μια μεταβλητή static int temp_id, η οποία χρησιμοποιείται για να αναθέσω τιμή στην id.
Οι private μεταβλητές της Object έχουν γίνει protected για να υπάρχει πρόσβαση των μεταβλητών στις υποκλασεις.
η Object::equal ελέγχει αν δυο αντικείμενα είναι ίσα συγκρίνοντας τα στοιχειά τους και επιστρέφοντας
την κατάλληλη boolean τιμή.
Η Object::identical ελέγχει αν δυο αντικείμενα έχουν την ίδια θέση μνήμης. Η συνάρτηση αυτή δεν είναι virtual
γιατί αν το Object κομμάτι της κλάσης είναι στην ίδια θέση μνήμης τότε και το υπόλοιπο θα είναι.
Η Object::clone είναι pure virtual γιατί οι υποκλασεις της μπορούν και κάνουν clone και το κομμάτι
της υπερκλασης τους.
Η Object::toString αφού είναι η τελική υπερκλαση, δημιουργεί ένα String temp με όρισμα την περιγραφή της Object και
το επιστρέφει.


Για την class String:
υποκλαση της Object, σαν κείμενο έχω την std::string, txt, η οποία αρχικοποιειται κατά τον constructor
της String.
Υπάρχουν δυο concat για λόγους ευκολίας, μια η οποία συγχωνεύει 2 String αντικείμενα και μια η οποία
παίρνει ως παραμέτρους ένα std::string και το ενώνει με το txt της String.
Η String::clone δημιουργεί έναν String* temp, ο οποίος έχει δεδομένα τα δεδομένα του this. Επίσης αντιγράφονται
και οι τιμές στο κομμάτι της υπερκλασης Object, με την βοήθεια της protected των private μεταβλητών της Object,
τέλος επιστρέφει το temp για να γίνει η ανάθεση του.
Η String::toString, δημιουργεί ένα String temp το οποίο παίρνει σαν όρισμα την περιγραφή της υπερκλασης(Object::toString)
πλας την περιγραφή του String κομματιού της κλάσης.
Η String::equal ελέγχει πρώτα την υπερκλαση της και μετά το δικό της μέλος.


Για την class Employee:
υποκλαση της Object, κατά την δημιουργία της παίρνει ως όρισμα μια αναφορά σε String για να αρχικοποιηθει το όνομα του Employee.
Οι private μεταβλητές της είναι protected για να έχουν πρόσβαση οι υποκλασεις της σε αυτές.
Η Employee::equal καλεί την equal της υπερκλασης της(Object::equal) και ανάλογα το αποτέλεσμα που θα βγάλει, ελέγχει αν στο
κομμάτι της class Employee τα στοιχειά είναι ίδια με το sec. Αν ναι επιστρέφει την κατάλληλη boolean τιμή.
Οι Employee::workOn και Employee::report συναρτήσεις είναι "pure virtual" συναρτήσεις(δηλαδή είναι κενές) όχι
με τον τρόπο, virtual void foo()=0, γιατί κάποιες υποκλασεις της κλάσης Employee δεν χρειάζονται όλες τις συναρτήσεις της,
άρα για να μην υπάρχει ο περιορισμός είναι κενές virtual συναρτήσεις.
Η Employee::toString δημιουργεί έναν String temp ο οποίος παίρνει ως όρισμα την περιγραφή της υπερκλασης της και προσθέτει
το δικό της κομμάτι της περιγραφής και το επιστρέφει.
Η Employee::clone είναι pure virtual γιατί οι υποκλασεις της μπορούν και κάνουν clone και το κομμάτι της υπερκλασης τους.


Για την class SecurityEmployee:
Υποκλαση της Employee, κατά την δημιουργία της παίρνει ως όρισμα μια αναφορά σε String και το κάνει clone στην Employee::name
Υπάρχουν 3 SecurityEmployee::workOn οι οποίες είναι μια για κάθε χώρο που πρέπει να δουλέψει ο SecurityEmployee. Αυτές εκτυπώνουν
ένα μήνυμα το οποίο λέει ότι ο εργάτης ξεκίνησε να δουλεύει στον συγκεκριμένο χώρο και καλούν την process του χώρου με όρισμα
το *this(τον εργάτη δηλαδή) για ενημερώσουν ότι ο συγκεκριμένος εργάτης δούλεψε στον χώρο.
Υπάρχουν επίσης 3 SecurityEmployee::report οι οποίες για κάθε χώρο που πρέπει να δουλέψει ο SecurityEmployee εκτυπώνει
και άλλο μήνυμα ότι συνεχίζει να δουλεύει στον συγκεκριμένο χώρο.
Η SecurityEmployee::equal ελέγχει αν το Employee κομμάτι του αντικειμένου είναι equal και επιστρέφει την αντίστοιχη boolean τιμή
(αφού δεν χρειάζεται να ελέγξει άλλα δεδομένα).
Η SecurityEmployee::clone δημιουργεί ένα temp αντικείμενο και αντιγραφεί σε αυτό τα δεδομένα των υπερκλασεων του, τέλος το επιστρέφει.
Η SecurityEmployee::toString δημιουργεί ένα String temp το οποίο παίρνει ως όρισμα την περιγραφή της υπερκλασης της και προσθέτει
και το δικό της κομμάτι της περιγραφής, τέλος το επιστρέφει.

Οι κλάσεις CleaningEmployee και MaintenanceEmployee είναι ίδιες με την SecurityEmployee άλλα διαφέρουν στα μηνύματα.

Επίσης η κλάση CleaningEmployee έχει μια έξτρα workOn/process, για τον χώρο CargoBay στον οποίο δεν πρέπει να δουλεύει,
άλλα ο CargoBay έχει μέσα ένα Equipment_space Και επειδή είναι υποκλαση της PrivateCompartment, πρέπει να δουλέψει και εκεί
για να είναι ready_check.


Για την κλαση PlaneComponent:
Υποκλαση της Object.
Οι συναρτήσεις PlaneComponent::process είναι δηλωμένες όπως και οι παραπάνω συνάρτησης της κλάσης Employee.
Η PlaneComponent::equal καλεί πρώτα την equal της υπερκλασης της και μετά επιστρέφει την τιμή.
Η PlaneComponent::toString συγχωνεύει την περιγραφή της υπερκλασης της με την δικιά της περιγραφή και την επιστρέφει.
Οι συναρτήσεις clone και ready_check είναι pure virtual γιατί οι υποκλασεις αυτής της κλάσης κάνουν ότι χρειάζεται και
για αυτή την κλάση.

Για τις υποκλασεις της PlaneComponent για να ελέγχουμε αν οι εργάτες έχουν δουλέψει στον συγκεκριμένο χώρο υπάρχουν κάποιες
boolean μεταβλητές οι οποίες αρχικοποιουνται κατά τον constructor κάθε κλάσης και αλλάζουν κατά την κλήση της process με όρισμα
τον συγκεκριμένο εργαζόμενο.


Για την κλαση PassengerCompartment:
υποκλαση της PlaneComponent, έχει ένα Sub_PassCompartment το οποίο έχει 1/4 πιθανότητα να δημιουργηθεί, αν δημιουργηθεί, έχει Και
αυτό 1/4 πιθανότητες να δημιουργηθεί ένα Sub_PassengerCompartment του Sub_PassCompartment.
Υπάρχει και δεύτερος constructor στην κλάση αυτή, ο οποίος χρησιμοποιείται στην clone για να δημιουργηθεί ένα PassengerCompartment
με σιγουριά ότι δεν θα δημιουργηθεί κανένα Sub_PassCompartment αυτού.
Οι PassengerCompartment::process βάζουν τον εργάτη να δουλέψει και στον υποχωρώ της, αν υπάρχουν. Καλεί επίσης και την report
για τον υποχωρο. Τέλος αλλάζει την boolean μεταβλητή που της αρμόζει.
Η PassengerCompartment::equal καλεί πρώτα την equal της υπερκλασης της και μετά ελέγχει για τις δικές της τιμές. Τέλος καλεί και την
equal για τον υποχωρο αν αυτός υπάρχει και επιστρέφει την κατάλληλη boolean τιμή.
Η PassengerCompartment::clone αντιγράφει τις τιμές από την this και αντιγράφει και τους υποχωρους αν αυτοί υπάρχουν.
Η PassengerCompartment::ready_check ελέγχει αν οι εργάτες έχουν δουλέψει στον χώρο αυτό, εκτυπώνει αντίστοιχο μήνυμα και την
περιγραφή του χώρου και τέλος ελέγχει και αν ο υποχωρος αυτός υπάρχει είναι ready.
Η PassengerCompartment::toString() συγχωνεύει την περιγραφή της υπερκλασης της και την δικιά της περιγραφή, αυτή η περιγραφή συμπεριλαμβάνει
και το ποιοι εργάτες έχουν δουλέψει στον χώρο και την περιγραφή των υποχωρων αν αυτοί υπάρχουν.


Για την κλαση PrivateCompartment:
Υποκλαση της PlaneComponent, είναι μια abstruct κλάση στην οποία οι υποκλασεις της πρέπει να δουλέψουν και σε αυτή για να είναι ready.
Αντίστοιχα οι συναρτήσεις της είναι παρόμοιες με τις συναρτήσεις παραπάνω και η clone είναι pure virtual γιατί οι υποκλίσεις της μπορούν
να αντιγράψουν τις protected private μεταβλητές της κλάσης αυτής.


Για την κλαση EquipmentCompartment:
υποκλαση της PrivateCompartment.
οι EquipmentCompartment::process αν χρειάζεται καλούν και τις process της υπερκλασης τους.
Η EquipmentCompartment::process(CleaningEmployee) δεν χρειάζεται για την συγκεκριμένη κλάση άλλα χρειάζεται για την PrivateCompartment.
Η EquipmentCompartment::equal ελέγχει πρώτα για την υπερκλαση της.
Η EquipmentCompartment::clone αντιγράφει επίσης και τις τιμές της υπερκλασης της.
Η EquipmentCompartment::ready_check ελέγχει πρώτα αν είναι ready η υπερκλαση της και μετά για τις δικές της τιμές.
Η EquipmentCompartment::toString συγχωνεύει την περιγραφή της υπερκλασης της με την δικιά της και προσθέτει αν έχουν δουλέψει οι εργαζόμενοι ή όχι.


Για την κλαση CargoBay:
υποκλαση της PrivateCompartment, εχει και ενα EquipmentCompartment
οι CargoBay::process αν χρειάζεται καλούν και τις process της υπερκλασης τους και τις process του equipment_space.
Η CargoBay::equal ελέγχει πρώτα για την υπερκλαση αυτής επίσης καλεί την equal για το equipment_space.
Η CargoBay::toString συγχωνεύει την περιγραφή της υπερκλασης της με την δικιά της, προσθέτει αν έχουν δουλέψει οι εργαζόμενοι ή όχι Και
προσθέτει και την περιγραφή του equipment_space.
Η CargoBay::ready_check ελέγχει πρώτα αν είναι ready η υπερκλαση της, μετά αν είναι ready ο equipment_space και μετά για τις δικές της τιμές.
Η CargoBay::clone αντιγράφει επίσης και τις τιμές της υπερκλασης της και καλεί την clone για την equipment_space.


Για την κλαση Plane:
υποκλαση της Object, έχει δυο constructor, έναν για το κανονικό ο οποίος αρχικοποιει τα μελή του Plane και έναν που χρησιμοποιείται στην
Plane::clone, δηλαδή ένα κενό αντικείμενο χωρίς αρχικοποιηση.
Στον πρώτο constructor υπάρχει και η υλοποίηση για το πόσα PassengerCompartment χρειάζονται στο αεροπλάνο. Αυτό είναι ανάλογα με το πλήθος των
επιβατών, κάθε PassengerCompartment(ανεξάρτητος αν έχει sub ή όχι) μπορεί να χωρέσει έως και 75 άτομα, και ανάλογα αν χρειάζονται ή όχι φτιάχνει
και παραπάνω από 1 PassengerCompartment στον array pl_PassComp.
Το έξτρα μέλος του class Plane, το size_PassComp είναι μια μεταβλητή η οποία καθορίζει το πόσα PassengerCompartment υπάρχουν στον πινάκα pl_PassComp
Οι Plane::process ελέγχουν αν τα μελή του Plane είναι ready ή όχι, αν όχι βάζει τον εργαζόμενο να δουλέψει εκεί και καλεί την report. Όταν τελειώσει από το
κάθε μέρος συνεχίζει στο επόμενο.
Για την Plane::process(CleaningEmployee), ο εργαζόμενος δουλεύει και στις EquipmentCompartment ώστε να είναι ready από το κομμάτι του PrivateCompartment.
Η Plane::equal ελέγχει αν είναι equal τα μελή του καλώντας επίσης και τις equal των κλάσεων αν χρειάζεται και τέλος καλεί και την equal της υπερκλασης της.
Η Plane::ready_check ελέγχει αν είναι ready τα μελή του αεροπλάνου και αν ναι τότε επιστρέφει την κατάλληλη boolean τιμή.
Η Plane::toString συγχωνεύει τις περιγραφές της υπόκλισης της Plane, των μελών της και την δικιά της περιγραφή και την επιστρέφει.
Η Plane::clone αντιγράφει με την χρήση της συνάρτησης ::clone για κάθε κλάση που χρειάζεται και αντιγράφει και τα δεδομενα του αεροπλάνου.

Η συνάρτηση clone_encrypt_and_print, παίρνει ως όρισμα μια αναφορά σε Object και την αντιγράφει σε μια temp μεταβλητή.
Μετά ελέγχει αν είναι ίσα και επιστρέφει το κατάλληλο μήνυμα.
Φτιάχνει άλλες δυο tempSTR με τις περιγραφές τους.
Για το κομματι της encrypt:
βρίσκει πρώτα μια τυχαία τιμή ανάμεσα στο 0 και στο μέγιστο πλήθος χαρακτήρων της περιγραφής της temp για το πόσοι χαρακτήρες θα αλλάξουν,
μέσα στην for η οποία έχει επαναλήψεις όσες και οι χαρακτήρες που θα αλλάξουν,
διαλέγει τυχαία ποιον χαρακτήρα να αλλάξει και διαλέγει τυχαία σε ποιον χαρακτήρα να μετατραπεί και καλεί την συνάρτηση String::updateAt
και μετατρέπει τον χαρακτήρα.
Έπειτα εκτυπώνει την αλλαγμένη περιγραφή και την παλιά περιγραφή, τις συνενώνει, εκτυπώνει το μήκος της μετά την ένωση,
εκτυπώνει τον μεσαίο χαρακτήρα ή τους μεσαίους χαρακτήρες ανάλογα αν είναι μονό ή ζυγό το πλήθος των χαρακτήρων μετά την συνένωση,
κάνει clear και εκτυπώνει το length της.


Output specifications:
Για όταν είναι να δουλέψουν οι Εργάτες και έχουν υποχωρους τα PlaneComponent:
I SecurityEmployee, started working into a Cargo Bay //Workon απο την Plane::process για την CargoBay
Equipment_space of CargoBay: I SecurityEmployee, started working into a Equipment Compartment //workOn απο την CargoBay::workOn για την EquipmentCompartment
SecurityEmployee keep working on EquipmentCompartment//report απο την CargoBay::workOn για την EquipmentCompartment
SecurityEmployee keep working on CargoBay//report απο την Plane::process για την CargoBay

I SecurityEmployee, started working into a Passenger Compartment//workOn απο την Plane::process για την PassengerCompartment
{Sub PassengerCompartment: I SecurityEmployee, started working into a Passenger Compartment //workOn απο την PassengerCompartment::workOn για τον υποχωρο της PassengerCompartment
SecurityEmployee keep working on PassengerCompartment //report απο την PassengerCompartment::workOn για τον υποχωρο της PassengerCompartment
}//ένδειξη ότι τέλειωσε ο υποχωρος της PassengerCompartment
SecurityEmployee keep working on PassengerCompartment //report απο την Plane::process για την PassengerCompartment


Για ready_check:
PrivateCompartment OK!//ready_check απο το PrivateCompartment κομματι της CargoBay
PrivateCompartment OK!//ready_check απο το PrivateCompartment κομματι της EquipmentCompartment της CargoBay
EquipmentCompartment OK!//ready_check απο την EquipmentCompartment της CargoBay
<Description of CargoBay>
CargoBay OK!//ready_check απο την CargoBay
