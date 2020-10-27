#include "InventoryItem.hpp"

InventoryItem::InventoryItem()
{
	itemName = " ";
	type = 0; 
}
std::string InventoryItem::getName()
{
	return itemName;
}
InventoryItem::~InventoryItem()
{

}