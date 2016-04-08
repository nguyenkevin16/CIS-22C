/** @file PlainBox.h */
#ifndef _PLAIN_BOX
#define _PLAIN_BOX

template < class ItemType >		// Indicates this is a template definition
class PlainBox 					// Declaration for the class PlainBox
{
	private:
  		ItemType item;				// Data field

	public:
	  	PlainBox ();								// Default constructor
	  	PlainBox (const ItemType & theItem);		// Parameterized constructor

	  	void setItem (const ItemType & theItem);	// Mutator method that can change the value of the data field
	  	ItemType getItem () const;					// Accessor method to get the value of the data field

};  // end PlainBox

#endif