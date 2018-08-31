#! /usr/bin/python

#--------------------------------------------------------------------------
# Why manually create all the needed files when the computer will 
# happily do that for you??
#

import os
import sys
import shutil
from argparse import ArgumentParser
from pathlib import Path

# The index of the current action that we are performing.
ActionIndex = 0
SubActionIndex = 0
ShowSubAction = False

LabName = ''
Destination = 'Labs'
ShouldOverwrite = False
IsVerbose = False
IsFilesOnly = False
FileNames = []

HeaderComment = '''
//--------------------------------------------------------------------------
// {0}.x 
//
// 
//
// 
//
'''


def main():

    global LabName
    global Destination
    global ShouldOverwrite
    global IsVerbose
    global IsFilesOnly
    global FileNames

    global ActionIndex
    global ShowSubAction
    global SubActionIndex

    global HeaderComment


    #------------------------------------------------------------
    # Parse the input arguments given by the user.

    parser = ArgumentParser()

    # We require the name of the lab. e.g. Lab1
    parser.add_argument("-l", "--labname", dest="mLabName", required=True,
        help="The name of the lab that you wish to create files for")

    # We require the destination of the lab 
    # By default, the Labs folder is where we want to put the labs.
    parser.add_argument("-d", "--destination", dest="mDestination", default="Labs", required=False, 
        help="The destination where the lab folder will be stored.")

    parser.add_argument("-f", "--filesonly", action="store_true", dest="mFilesOnly", help="Create the files inside an existing directory.")

    parser.add_argument("-n", "--names", required=True, nargs='+', dest="mFileNames", help="Specify a list of files to create in the lab.")

    # Overwrite any lab folder that already exists! You must be careful with this one. Should disable after debugging phase.
    parser.add_argument("-o", "--overwrite", action="store_true", dest="mShouldOverwrite", help="Overwrite any folders/files that exist in the given lab")

    # Verbose output.
    parser.add_argument("-v", "--verbose", dest="mIsVerbose", action="store_true", help="Print out what the script is doing")

    # Parse the args
    args = parser.parse_args()

    # Pull variables out of the argparser for convenience.
    LabName = args.mLabName
    Destination = args.mDestination
    ShouldOverwrite = args.mShouldOverwrite
    IsVerbose = args.mIsVerbose
    IsFilesOnly = args.mFilesOnly
    FileNames = args.mFileNames

    Dirs = GetFolderPaths(LabName, Destination)

    LabDir = Dirs[0]
    HeaderDir = Dirs[1]

    # If we want to create the files only then we dont need to create the directory.
    if not IsFilesOnly:

        CreateFolderStructure(LabName, Destination, ShouldOverwrite)
        
    
    # Foreach filename that we want to create, create the cpp file and the header file.
    # Then populate each file with the basic contents.
    for FileName in FileNames:
        
        

        # Get the file URL.
        FileDirs = BuildFilePaths(LabName, Destination, FileName)

        FileCpp = FileDirs[0]
        FileHpp = FileDirs[1]

        Log('Trying to create: {0} and {1}'.format(FileCpp, FileHpp))
        
        ActionIndex = ActionIndex - 1

        #------------------------------------------------------------
        
        # Run a basic check on the filename to see if it exists.
        BasicFileCheck(FileCpp)

        # Open the file that was created.
        
        with open(FileCpp, mode='x') as handle:

            # Write the header to the file.
            handle.write(HeaderComment.format(LabName) + '\r\n')
            handle.write('\r\n')
            handle.write('\r\n')

            # Write the include line to the file.
            handle.write("#include \"{0}.hpp\" \r\n\r\n".format(FileName))

            # Write the namespace
            handle.write("namespace {0} \r\n".format(LabName))
            handle.write("{\r\n\r\n")

            # Write the blank function call.
            handle.write("\tvoid {0}()\r\n".format(FileName))
            handle.write("\t{ \r\n\r\n")
            handle.write("\t} \r\n\r\n")

            # Write the end of the namespace
            handle.write('}')
            handle.write(" // end namespace {0} \r\n".format(LabName))

        

        #------------------------------------------------------------
        SubActionIndex = 0
        

        # Run a basic check on the filename to see if it exists.
        BasicFileCheck(FileHpp)


        # Open the file that was created.
        
        with open(FileHpp, mode='x') as handle:
            
            # Write the header to the file.
            handle.write(HeaderComment.format(LabName) + '\r\n')

            handle.write("#ifndef {0}_HPP\r\n".format(FileName))
            handle.write("#define {0}_HPP\r\n\r\n".format(FileName))

            # Write the include line to the file.
            handle.write("#include \"mbed.hpp\" \r\n")
            handle.write("#include \"stdint.hpp\" \r\n\r\n\r\n")

            # Write the namespace
            handle.write("namespace {0} \r\n".format(LabName))
            handle.write("{\r\n\r\n")

            # Write the blank function call.
            handle.write("\tvoid {0}();\r\n\r\n".format(FileName))

            # Write the end of the namespace
            handle.write("}")
            handle.write(" // end namespace {0} \r\n\r\n".format(LabName))
            
            # Close the header guard.
            handle.write("#endif")

        #ShowSubAction = False
        ActionIndex = ActionIndex + 1

    # Close for loop

    ShowSubAction = False 

    Log('Finished')



def BasicFileCheck(FileURL):

    global ShouldOverwrite
    global ShowSubAction

    ShowSubAction = True
    SubActionIndex = 0

    # Get the path to the file.
    my_file = Path(FileURL)

    # Check to see if the file already exists.
    if my_file.is_file():
        
        Log('File already exists.')

        if ShouldOverwrite:
            Log('Overwriting file.')
            os.remove(FileURL)

    else:
        Log('File does not exist. Creating it now.')
    
    # Create the file now.
    #print(FileURL)
    #os.mknod(FileURL)




#------------------------------------------------------------
# Create the URLs to the folders/files that we want to
# create according to user input.

def GetFolderPaths(LabName, Destination):

    IS_WINDOWS = os.name == 'nt'

    lab_dir = ""
    header_dir = ""

    if IS_WINDOWS:
        lab_dir = ".\\" + Destination + "\\" + LabName
        header_dir = lab_dir + "\\Headers"

    else:
        lab_dir = "./" + Destination + "/" + LabName
        header_dir = lab_dir + "/Headers"
    
    return (lab_dir, header_dir)


#------------------------------------------------------------
# Build a file path for a given filename.

def BuildFilePaths(LabName, Destination, FileName):
    
    IS_WINDOWS = os.name == 'nt'

    # Create the URL for the files that we are going to create.
    dirs = GetFolderPaths(LabName, Destination)
    cpp_dir  = dirs[0]
    hpp_dir  = dirs[1]

    cpp_file = ""
    hpp_file = ""

    if IS_WINDOWS:
        cpp_file = cpp_dir + "\\" + FileName + ".cpp"
        hpp_file = hpp_dir + "\\" + FileName + ".hpp" 
    else:
        cpp_file = cpp_dir + "/" + FileName + ".cpp"
        hpp_file = hpp_dir + "/" + FileName + ".hpp" 
    
    return (cpp_file, hpp_file)


#------------------------------------------------------------
# Create the new lab directory if it doesnt exist already.
# If it does exist, throw an error, and require the user to 
# set the override flag.

def CreateFolderStructure(LabName, Destination, Overwrite):
    
    dirs = GetFolderPaths(LabName, Destination)

    lab_dir = dirs[0]
    header_dir = dirs[1]

    Log('Lab path is: {0}'.format(lab_dir))
    
    # If the directory doesn't already exist, then we create it.
    if not os.path.exists(lab_dir):
        
        Log("Lab destination path doesn't exist. Adding folders.")

        os.makedirs(lab_dir)
        os.makedirs(header_dir)
    
    else:

        if not Overwrite:
            print('The folder: %s already exists and will not be overwritten.' % lab_dir)
            print('Use the -o switch to delete the folder and contents and proceed.')
            print('Or use the -f switch to only create the files inside of the existing folder.')
            
        else:
            
            Log("Deleting existing folder: {0}".format(lab_dir))
                    
            try:
                shutil.rmtree(lab_dir)
                os.makedirs(lab_dir)
                os.makedirs(header_dir)

            except OSError as e:
                print ("Error: %s - %s." % (e.filename, e.strerror))
    

def Log(TheString):
    
    global ActionIndex
    global SubActionIndex
    global ShowSubAction

    global IsVerbose

    if IsVerbose:
        
        if ShowSubAction:
            print('[{0}.{1}]: {2}'.format(ActionIndex, SubActionIndex, TheString))

            SubActionIndex = SubActionIndex + 1

        else:
            print('[{0}]: {1}'.format(ActionIndex, TheString))
        
            ActionIndex = ActionIndex + 1


if __name__ == "__main__":
    main()