#!/bin/bash

PS3="botato:__:"
# colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

options=("Create Database" "List Databases" "Connect To Database" "Drop Database" "quit")
secondOptions=("Create Table" "List Tables" "Drop Table" "Insert into Table" "Select From Table" "Delete From Table" "Update Table" "Exit Database") 
echo "=========================================="
echo "=================DBMS====================="
echo "=========================================="
select op in "${options[@]}";
do
    case $op in
        "Create Database")
            read -p "input database  name you want: " dbName
            if [ -z $dbName ]; then
                 echo "DB Name Cant be Empty"
            else     
                  mkdir $dbName.db
                  echo "your database $dbname is created successfully"
            
            fi 
            ;;
        "List Databases")
         dbs=$(ls -d *.db 2>/dev/null)
           if [ -z "$dbs" ]; then
              echo "No databases"
          else
             echo "Databases:"
             for db in $dbs; do
                  echo "${db%.db}"
               done 
           fi

            ;;
        "Connect To Database")
            read -p "Input database name to connect to: " dbName
               dbDir="${dbName}.db"

           if [ -z "$dbName" ]; then
                echo "Database name cannot be empty"
                   continue 
           fi

          if [ -d "$dbDir" ]; then
          cd "$dbDir" || exit
             echo "Connected to database: $dbName"
          else
          echo "Database '$dbName' does not exist"
          continue 
          fi


            
            select innerOp in "${secondOptions[@]}";
            do
                case $innerOp in
                    "Create Table")
                        read -p "please input table name: " tableName

                        if [[ -z $tableName ]]; then
                            echo -e "${RED}you did not input a table name${NC}"
                            continue
                        elif [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table exists already${NC}"
                            continue
                        fi

                        if ! [[ $tableName =~ ^[[:alnum:]_]+$ ]]; then
                            echo -e "${RED}table must be of upper | lower | _ characters only${NC}"
                            continue
                        fi

                        tableName="$tableName.tbl"
                        pkSet="false"

                        read -p "please input the number of columns: " colNumbers

                        if ! [[ $colNumbers =~ ^[1-9][0-9]*$ ]]; then
                            echo -e "${RED}invalid column number${NC}"
                            continue
                        fi

                        metadata=""

                        for (( i=1; i<=$colNumbers; i++ ))
                        do
                            read -p  "column number $i name: " colName
                            if [[ -z $colName || $colName =~ [:|] ]]; then
                                echo -e "${RED}invalid column name${NC}"
                                ((i--))
                                continue
                            fi
                            if echo "$metadata" | tr '|' '\n' | cut -d':' -f1 | grep -qx "$colName"; then
                                echo -e "${RED}Duplicated column name${NC}"
                                # exit 1
                                ((i--))
                                continue
                            fi
                            read -p "column number $i data type: " colDataType
                            if [[ -z $colDataType ]] || [[ $colDataType != "string" && $colDataType != "int" ]]; then
                                echo -e "${RED}empty or Unsupported data type${NC}"
                                ((i--))
                                continue
                            fi
                            read -p "is column primary key? (y|n) " colPk

                            if [[ -z $colPk ]] || [[ $colPk != "y" && $colPk != "n" ]]; then
                                echo -e "${RED}invalid option selected${NC}"
                                ((i--))
                                continue
                            fi

                            if  [[ $colPk == "y" ]]; then
                                if [[ $pkSet == "true" ]]; then
                                    echo -e "${RED}you already have a primary key${NC}"
                                    ((i--))
                                    continue
                                else
                                    pkSet="true"
                                fi

                            fi

                            metadata+="$colName:$colDataType"
                            if [[ $colPk == "y" ]]; then
                                metadata+=":pk|"
                            else
                                metadata+="|"
                            fi

                        done

                        metadata=${metadata%|}

                        touch $tableName

                        echo $metadata > $tableName
                        ;;
                    "List Tables")
                        tbls=$(ls -A *.tbl 2>/dev/null)
                       if [ -z "$tbls" ]; then
                      echo "No Tables In $dbName DataBase "
                       else
                      echo "Tables In $dbName DataBase :"
                     for tb in $tbls; do
                          echo "${tb%.tbl}"
                         done
                       fi
                        ;;
                    "Drop Table")
                        read -p "input table name to delete" tableName
                        
                        if ! [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table $tableName not existing${NC}"
                            continue
                        fi
                        
                        echo "deletign table $tableName"
                        rm "$tableNam.tbl"
                        ;;
                    "Insert into Table")
                        read -p "Input table name: " tableName

                        if ! [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table $tableName not existing${NC}"
                            continue
                        fi

                        tableName="$tableName.tbl"


                        metaData=$(head -1 $tableName)

                        iterator=1
                        record=""

                        while [[ -n `echo $metaData | cut -d "|" -f$iterator` ]]
                        do
                            columnMetaData=`echo $metaData | cut -d "|" -f$iterator`
                            columnName=`echo $columnMetaData | cut -d ":" -f1`
                            columDataType=`echo $columnMetaData | cut -d ":" -f2`
                            isColumnPk=`echo $columnMetaData | cut -d ":" -f3`

                            read -p "inputing data for column ($columnName) of $columDataType data type: " data
                            if [[ $data =~ [|:] ]]
                            then
                                echo -e "${YELLOW}Invalid characters${NC}"
                                continue
                            fi
                            if [[ -n $isColumnPk ]]; then
                                if [[ $(tail -n +2 $tableName | cut -d "|" -f$iterator | grep -w "$data") ]]; then
                                    echo -e "${YELLOW}invalid primary key, chose different one${NC}"
                                    continue
                                fi
                            fi
                            if [[ $columDataType == "int" ]] && [[ $data =~ ^[0-9]+$ ]]; then
                                record+="$data|";
                                ((iterator++))

                            elif [[ $columDataType == "string" ]] && [[ -n $data ]]; then
                                record+="$data|";
                                ((iterator++))
                            else
                                echo -e "${YELLOW}invalid input, column $columnName must be $columDataType${NC}"
                            fi
                        done
                        record=${record%|}

                        echo $record >> $tableName
                        ;;
                    "Select From Table")
                        read -p "Input table name: " tableName

                        if ! [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table $tableName not existing${NC}"
                            continue
                        fi

                        tableName="$tableName.tbl"
                        metaData=$(head -1 $tableName)

                        
                        columns=($(echo "$metaData" | tr "|" "\n" | cut -d":" -f1))

                        select selectOp in "Select All" "Select Column" "Select By Column" "Back"
                        do
                            case $selectOp in

                                "Select All")
                                    echo -e "${GREEN}------ DATA ------${NC}"

                                    echo "${columns[*]}" | tr " " "|"
                                    echo "-----------------------------"

                                    tail -n +2 $tableName
                                    continue
                                    ;;

                                "Select Column")
                                    select colName in "${columns[@]}" "Back"
                                    do
                                        if [[ $colName == "Back" ]]; then
                                            break
                                        elif [[ -z $colName ]]; then
                                            echo -e "${RED}invalid choice${NC}"
                                            continue
                                        fi

                                        colIndex=$(echo "$metaData" | tr "|" "\n" | awk -F:    '{print NR ":" $1}' | grep ":$colName$" | cut -d":" -f1)

                                        echo "$colName"
                                        echo "-------------"
                                        tail -n +2 $tableName | cut -d "|" -f$colIndex
                                        
                                    done
                                    continue
                                    ;;

                                "Select By Column")
                                    select colName in "${columns[@]}" "Back"
                                    do
                                        if [[ $colName == "Back" ]]; then
                                            break
                                        elif [[ -z $colName ]]; then
                                            echo -e "${RED}invalid choice${NC}"
                                            continue
                                        fi

                                        colIndex=$(echo "$metaData" | tr "|" "\n" | awk -F: '{print NR ":" $1}' | grep ":$colName$" | cut -d":" -f1)

                                        read -p "Enter value to search for: " searchValue

                                        echo "${columns[*]}" | tr " " "|"
                                        echo "------------------------------------------"

                                        tail -n +2 $tableName | awk -F"|" -v idx="$colIndex" -v val="$searchValue" '$idx==val'
                                        
                                    done
                                    continue
                                    ;;

                                "Back")
                                    break
                                    ;;

                                *)
                                    echo -e "${RED}invalid option${NC}"
                                    ;;
                            esac
                        done
                        ;;

                    "Delete From Table")
                        read -p "Input table name: " tableName

                        if ! [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table $tableName not existing${NC}"
                            continue
                        fi

                        tableName="$tableName.tbl"
                        metaData=$(head -1 $tableName)
                        columns=($(echo "$metaData" | tr "|" "\n" | cut -d":" -f1))

                        select delOp in "Delete All" "Delete By Column" "Back"
                        do
                            case $delOp in

                                "Delete All")
                                    read -p "Are you sure? (y/n): " confirm
                                    if [[ $confirm == "y" ]]; then
                                        sed -i '2,$d' $tableName
                                        echo -e "${GREEN}all records deleted${NC}"
                                    fi
                                    continue
                                    ;;

                                "Delete By Column")
                                    select colName in "${columns[@]}" "Back"
                                    do
                                        [[ $colName == "Back" ]] && break
                                        [[ -z $colName ]] && echo -e "${RED}invalid option${NC}" && continue

                                        colIndex=$(echo "$metaData" | tr "|" "\n" | awk -F: '{print NR ":" $1}' | grep ":$colName$" | cut -d":" -f1)

                                        read -p "Enter value to delete by: " delValue

                                        countBefore=$(wc -l < $tableName)
                                        sed -i "/^$(tail -n +2 $tableName | awk -F'|' -v i="$colIndex" -v v="$delValue" '$i==v{print}')$/d" $tableName
                                        countAfter=$(wc -l < $tableName)

                                        deletedCount=$((countBefore - countAfter))

                                        if [[ $deletedCount -eq 0 ]]; then
                                            echo -e "${YELLOW}no matching records found${NC}"
                                        else
                                            echo -e "${GREEN}$deletedCount record(s) deleted successfully${NC}"
                                        fi

                                    
                                    done
                                    continue
                                    ;;

                                "Back")
                                    break
                                    ;;

                                *)
                                    echo -e "${RED}invalid option${NC}"
                                    ;;
                            esac
                        done
                        ;;

                    "Update Table")
                        read -p "Input table name: " tableName

                        if ! [[ -f "$tableName.tbl" ]]; then
                            echo -e "${RED}table $tableName not existing${NC}"
                            continue
                        fi

                        tableName="$tableName.tbl"
                        metaData=$(head -1 $tableName)
                        columns=($(echo "$metaData" | tr "|" "\n" | cut -d":" -f1))

                        
                        echo "Select column to search by:"
                        select searchCol in "${columns[@]}" "Back"
                        do
                            if [[ $searchCol == "Back" ]] ; then
                                break
                            elif [[ -z $searchCol ]] ; then 
                                echo -e "${RED}invalid option${NC}" 
                                continue
                            fi
                            searchColIndex=$(echo "$metaData" | tr "|" "\n" | awk -F: '{print NR ":" $1}' | grep ":$searchCol$" | cut -d":" -f1)

                            read -p "Enter value to search for: " searchValue

                           
                            matchedRows=$(tail -n +2 $tableName | awk -F"|" -v idx="$searchColIndex" -v val="$searchValue" '$idx==val')

                            if [[ -z $matchedRows ]]; then
                                echo -e "${YELLOW}no matching records found${NC}"
                                continue
                            fi

                            echo -e "${GREEN}Found records:${NC}"
                            echo "${columns[*]}" | tr " " "|"
                            echo "$matchedRows"

                            
                            echo "Select column to update:"
                            select updateCol in "${columns[@]}" "Back"
                            do
                                [[ $updateCol == "Back" ]] && break
                                [[ -z $updateCol ]] && echo -e "${RED}invalid option${NC}" && continue

                                updateColIndex=$(echo "$metaData" | tr "|" "\n" | awk -F: '{print NR ":" $1}' | grep ":$updateCol$" | cut -d":" -f1)
                                colData=$(echo "$metaData" | cut -d"|" -f$updateColIndex)
                                updateColType=$(echo "$colData" | cut -d":" -f2)
                                isPk=$(echo "$colData" | cut -d":" -f3)

                                read -p "Enter new value for $updateCol: " newValue

                               
                                if [[ $updateColType == "int" ]] && ! [[ $newValue =~ ^[0-9]+$ ]]; then
                                    echo -e "${YELLOW}invalid input, must be integer${NC}"
                                    continue
                                fi

                                if [[ $newValue =~ [|:] ]]; then
                                    echo -e "${YELLOW}Invalid characters${NC}"
                                    continue
                                fi

                               
                                if [[ -n $isPk ]]; then
                                    if tail -n +2 $tableName | cut -d "|" -f$updateColIndex | grep -qw "$newValue"; then
                                        echo -e "${YELLOW}invalid primary key, already exists${NC}"
                                        continue
                                    fi
                                fi

                               
                                awk -F"|" -v OFS="|" -v sidx="$searchColIndex" -v sval="$searchValue" -v uidx="$updateColIndex" -v uval="$newValue" \
                                    'NR==1 {print; next} $sidx==sval {$uidx=uval} {print}' $tableName > temp && mv temp $tableName

                                echo -e "${GREEN}record(s) updated successfully${NC}"
                            
                            done
                            continue
                        done
                        ;;
                    "Exit Database")
                        echo "Exitting database $dbName"
                        cd ..
                        break
                        ;;	
                esac
            done
            ;;
        "Drop Database")
            read -p "input database name to drop: " dbName
            dbDir="${dbName}.db"
            if [ -d "$dbDir" ]; then
            rm -rf "$dbName.tbl"
            echo "$dbName database deleted successfully"
            
            else
          echo "Database '$dbName' does not exist"
          continue 
          fi
            
            ;;
        "quit")
            echo "exiting data base managment system"
            break
            ;;

        *)
            echo "not implmented yet"
            ;;
    esac
done
