# Git Cheatsheet

### Configure For First Time

```bash
# Your username
git config --global user.name "John Doe"

# Your [Github] email
git config --global user.email "johndoe@example.com"

# (Optional) Change the default branch name "master" to "main"
git config --global init.defaultBranch main
```

### Generate an SSH Key and Add it to Github

[How to connect git with Github](https://docs.github.com/en/authentication/connecting-to-github-with-ssh)

### Get help for Git

```bash
git help

# Get help about something specific
git help commit
```

### Cloning (Copying) Respositories

```shell
git clone https://github.com/username/myproject.git

# if you want to rename the folder:
git clone https://github.com/username/myproject.git my_proj_folder
```

### Show All Changes Made

```shell
git log
git log --stat
git log --pretty=format:"%h - %an, %ar : %s"
git log --since=2.weeks
```

### Initialize a repository in current directory

```bash
git init

# Check if files have been modified/staged/commited
git status
```

### STAGING files to commit

```bash
# create a README.md file
echo "# Readme" >> README.md

git add README.md # adds only README.md

# Other Options
git add -A   # adds all changes, deletions, and new files
git add .    # adds new files and modifications, without deletions
git add -u   # adds modifications and deletions, but no new files
```

### Commiting STAGED files

```shell

git commit # You have to type in your message in a text editor

# Pass in your message as an argument
git commit -m "My Message: Added README.md"

# Stage all files AND commit them together
git commit -a -m "two-one-solution !"

```

### Removing a file

```shell
git rm myfile.txt # stages the file's removal in git
rm myfile.txt # deletes the file permanently

# Other Examples
git rm app_logs/\*.log # stage removal of all .log files in the folder app_logs
```

### Renaming Files

```shell
git mv README.md README
```
---
<br><br>
# Common Commands Reference

## Recording Session from Terminal

- On macOS: <br> `script script - linux - $(date +%F).log -- timing=time - $(date +%F).txt`
- On Linux <br> `script - r script - mac - $(date +%F).log`

Use `exit` or `Ctrl+d` to stop recording.

## Compiling C++ Programs

```bash
g++ -g -O0 -std=c++17 -Wall code.cpp -o code_binary.out
```

## File Operations

```
ls # list files
ls -al # list files with details and show hidden

pwd # print working directory
cd # change directory
mv source dest # move or rename files
cp source dest # copy files
rm -rf ./filename ./folder # delete files and folders
```
