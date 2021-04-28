#!/bin/bash

Phonebook="Phonebook.txt"
	main () {
	exit=0
	while [ $exit -ne 1 ]
	do
		echo "Would you like to list, add, edit, delete, or exit?"
		read action
		echo "Please enter the name in the form Firstname Lastname"
		read Name
		echo "Please enter the address in the form housenumber street, city"
		read Address
		echo "Please enter the phone number in the form 9999999999"
		read Number
		if [ "$action" = "list" ]
		then
			list_entry $Name
		elif [ "$action" = "add" ]
		then
			add_entry $Name $Address $Number
		elif [ "$action" = "edit" ]
		then
			edit_entry $Name $Address $Number
		elif [ "$action" = "delete" ]
		then
			delete_entry $Name
		else
			exit=1
		fi
	done
	exit 0
	}

	list_entry () {
		Phonebook="Phonebook.txt"
		grep -i $1 $Phonebook
	}

	delete_entry () {
		Phonebook="Phonebook.txt"
		sed -i "/$1/d" $Phonebook
		sort $Phonebook
	}

	edit_entry () {
		Phonebook="Phonebook.txt"
		echo "Please enter the new name in the form Firstname Lastname"
		read newName
		echo "Please enter the new address"
		read newAddress
		echo "Please enter the new phone number in the form 9999999999"
		read newNumber
		sed -i "s/.*$Name $Address $Number.*/$newName $newAddress $newNumber./" $Phonebook
		sort $Phonebook
	}
	
	add_entry () {
		Phonebook="Phonebook.txt"
		echo "Please enter the new name in the form Firstname Lastname"
                read newName
                echo "Please enter the new address"
                read newAddress
                echo "Please enter the new phone number in the form 9999999999"
                read newNumber
		sed -i "1 a $newName $newAddress $newNumber" $Phonebook
		sort $Phonebook
	}
main			