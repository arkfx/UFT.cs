import subprocess

# Start the C script in a separate process
c_process = subprocess.Popen(["/workspaces/UFT.cs/Cpython/backC/test1.c"])

# Start the Python script in a separate process
python_process = subprocess.Popen(["python", "/workspaces/UFT.cs/Cpython/frontPY/test2.py"])

# Wait for both processes to finish
c_process.wait()
python_process.wait()
