"""
This module runs two scripts at the same time.

The first script is located at /workspaces/UFT.cs/Cpython/backC/test1.c and is compiled using gcc.
The second script is located at /workspaces/UFT.cs/Cpython/frontPY/test2.py and is run using Python.

This module uses the subprocess module to start the two scripts in separate processes.
"""
import subprocess

# Rest of the code goes here

subprocess.Popen(['gcc', '/workspaces/UFT.cs/Cpython/backC/test1.c', '-o', 'test1'])
subprocess.Popen(['./test1'])


# Run test2.py in the background
subprocess.Popen(['python', '/workspaces/UFT.cs/Cpython/frontPY/test2.py'])
