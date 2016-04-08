/** @file PlainBox.h */
#ifndef _PLAIN_BOX
#define _PLAIN_BOX
#include "BoxInterface.h"

template <class ItemType>							// Indicates this is a template definition
class PlainBox : public BoxInterface<ItemType>		// Declaration for the class PlainBox
{
	private:
  		ItemType item;				// Data field

	public:
	  	PlainBox ();								// Default constructor
	  	PlainBox (const ItemType& theItem);			// Parameterized constructor

	  	virtual void setItem (const ItemType & theItem);	// Mutator method that can change the value of the data field
	  	virtual ItemType getItem () const;					// Accessor method to get the value of the data field
};  // end PlainBox

template <class ItemType> PlainBox <ItemType> ::PlainBox()
{
}   // end default constructor

template <class ItemType> PlainBox <ItemType> ::PlainBox(const ItemType & theItem)
{
	item = theItem;
}   // end constructor

template <class ItemType> void PlainBox <ItemType> ::setItem(const ItemType & theItem)
{
	item = theItem;
}   // end setItem

template <class ItemType> ItemType PlainBox <ItemType> ::getItem() const
{
	return item;
}   // end getItem

#endif