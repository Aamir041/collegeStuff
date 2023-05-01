while true; do 
    echo "Student Database Menu:"
    echo "Press 1 to create a database"
    echo "Press 2 to insert a record in database"
    echo "Press 3 to view database"
    echo "Press 4 to delete a record in database"
    echo "Press 5 to modify a record in database"
    echo "Press 6 to search a student in database"
    echo "Press 7 to exit"

    read choice # takes input to ans stores in variable called choice
    
    case $choice in
        1)
            echo "Enter name of database: "
            read db_name
            touch "$db_name.txt" # creates a text file 
            echo "Database Created! $db_name"
            ;;
        
        2)
            echo -n "Enter name of student: "
            read name
            
            echo -n "Enter roll number of student: "
            read roll

            echo -n "Enter marks 1 of student: "
            read marks1

            echo -n "Enter marks 2 of student: "
            read marks2

            echo -n "Enter marks 3 of student: "
            read marks3

            echo "$name|$roll|$marks1|$marks2|$marks3" >> "$db_name.txt" # appends given data in file >> is for appending
            echo "Record added successfully"
            ;;

        3)
            cat "$db_name.txt"
            ;;

        4)
          echo -n "Enter roll number of student: "
          read roll_num
          record=$(grep "^.*|$roll_num|" "$db_name.txt") # stores record from givern roll number
          size=${#record} #stores length of record
          if [ $size -gt 0 ]; then # if record length > 0 records exist
            sed -i "/$roll_num/d" "$db_name.txt" # deletes record from file
            echo "record deleted"
          else
            echo "Record Not Found"
          fi
          ;;
        
        5)
          echo -n "Enter roll number of student to modify: "
          read roll_num
          record=$(grep "^.*|$roll_num|" "$db_name.txt")
          size=${#record}
          if [ $size -gt 0 ]; then
            echo -n "Enter name of student: "
            read name
            
            echo -n "Enter roll number of student: "
            read roll

            echo -n "Enter marks 1 of student: "
            read marks1

            echo -n "Enter marks 2 of student: "
            read marks2

            echo -n "Enter marks 3 of student: "
            read marks3

            sed -i "s/^.*|$roll_num|.*$/$name|$roll|$marks1|$marks2|$marks3/"  "$db_name.txt" # replaces current content in file with new content
            echo "Data Modified"
          else
            echo "Record Not Found"
          fi
          ;;
        6) # if user inputs 6
          echo -n "Enter roll number: "
          read roll
          record=$(grep "^.*|$roll|" "$db_name.txt")
          size=${#record}
          if [ $size -gt 0 ]; then
            echo "$record"
          else
            echo "Record not found"
          fi #for closing if else block
          ;; # equivalent to break in switch case statement 

        7) # if user inputs 7
            exit 0 #break looop
            ;;
    esac # for closing switch-case block
done # close while looop block

