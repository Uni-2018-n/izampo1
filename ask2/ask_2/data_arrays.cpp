#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const string phrase_Array[40]= {"I will never be this young again. Ever. Oh damn… I just got older.", "She always speaks to him in a loud voice.","He told us a very exciting adventure story.",
"The body may perhaps compensates for the loss of a true metaphysics.","Sixty-Four comes asking for bread.","I want to buy a onesie… but know it won’t suit me.",
"If you like tuna and tomato sauce- try combining the two. It’s really not as bad as it sounds.","He didn’t want to go to the dentist, yet he went anyway.",
"I am counting my calories, yet I really want dessert.","The old apple revels in its authority.","Last Friday in three week’s time I saw a spotted striped blue worm shake hands with a legless lizard.",
"I would have gotten the promotion, but my attendance wasn’t good enough.","There was no ice cream in the freezer, nor did they have money to go to the store.",
"She wrote him a long letter, but he didn't read it.","Yeah, I think it's a good environment for learning English.","The waves were crashing on the shore; it was a lovely sight.",
"He said he was not there yesterday; however, many people saw him there.","Check back tomorrow; I will see if the book has arrived.","The quick brown fox jumps over the lazy dog.",
"Please wait outside of the house.","Two seats were vacant.","She did not cheat on the test, for it was not the right thing to do.","The lake is a long way from here.",
"She borrowed the book from him many years ago and hasn't yet returned it.",
"What was the person thinking when they discovered cow’s milk was fine for human consumption… and why did they do it in the first place!?","She was too short to see over the fence.",
"Is it free?","Let me help you with your baggage.","I am never at home on Sundays.","She only paints with bold colors; she does not like pastels.","The shooter says goodbye to his love.",
"I checked to make sure that he was still alive.","Don't step on the broken glass.","Malls are great places to shop; I can find everything I need under one roof.",
"Sometimes, all you need to do is completely make an ass of yourself and laugh it off to realise that life isn’t so bad after all.",
"A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.",
"If the Easter Bunny and the Tooth Fairy had babies would they take your teeth and leave chocolate for you?","How was the math test?","Cats are good pets, for they are clean and are not noisy.",
"My Mum tries to be cool by saying that she likes all the same things that I do."}; //40



const string name_array[40]={"Harvey Hutchinson","Shon Hernandez","Raleigh Huff","Nathanial Hester","Noelle Riley","Edwin Cabrera","Elma Blair","Janine Ortiz","Jewell Barber","Bianca Farrell",
"Wally Ingram","Natasha Barnett","Lucas Hill","Dawn Mckee","Tricia Glover","Lea Weiss","Isiah Pugh","Lauren Woods","Antonio Suarez","Sofia Horton","Evangeline Buckley","Ruben Hopkins",
"Savannah Hinton","Tamika Hooper","Eve Mccormick","Lawanda Mccullough","Rita Terrell","Jillian Haley","Marva Shaffer","Eloise Singleton","Teodoro Sampson","Rudy Villegas","Vicente Kaiser",
"Lon Simon","Guillermo Howell","Ginger Savage","Alton Buck","Luisa Blackwell","Manuela Wiggins","Roslyn Zavala"}; //40

const string title_Array[40]={"Duke Of The Forsaken","Priest Without Faith","Guardians With Honor","Kings Of The Forsaken","Pirates And Heroes","Doctors And Mice","Achievement Of Despair",
"Restoration Of The Ancestors","Blood At The Dark","Choking In The City","Tree Without Desire","Priest Without A Home","Guardians With Immortality","Men Of The Frontline","Spiders And Butchers",
"Vultures And Trees","Union Of Utopia","End Of Freedom","Separated In The Titans","Scared At Eternity","Rebel Of Darkness","Cyborg Of History","Priests Of Eternity","Serpents Without Duty",
"Rebels And Wives","Friends And Enemies","Country Without Desire","Fate Of The Great","Breath Of My Nightmares","Inventing The Forest","Hero Of The West","Knight Of Desire","Aliens Of The East",
"Swindlers Of The River","Lions And Gods","Companions And Descendants","Moon Without Flaws","Source Without Fear","Vanish In The World","Life Beneath The King"};//40



const string get_random_name(){

  int x= rand() % 5;//for demo its 5 so each user will have more than 1 post created
  return name_array[x];
}

const string get_random_phrase(){

  int x= rand() % 40;
  return phrase_Array[x];
}

const string get_random_title(){

  int x= rand() % 40;
  return title_Array[x];
}
