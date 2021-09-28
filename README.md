# Hacktoberfest-2021
Repository designed for beginner to contribute to open-source 



## What is Hacktoberfest?
Hacktoberfest is a month long virtual festival event to celebrate open source contributions presented by DigitalOcean and DEV. It is the easiest way to get into open source!

![Capture](https://user-images.githubusercontent.com/55937303/134947263-53b4184a-1090-4fd7-89c4-865952353d06.PNG)
You can learn more about Hacktoberfest [here!](https://hacktoberfest.digitalocean.com/)

**Rules** \
To qualify for the official limited edition Hacktoberfest shirt, you must register and make four pull requests (PRs) between October 1-31 (in any time zone). PRs can be made to any public repository on GitHub/GitLab, which solve the issues labeled as `hacktoberfest`. 
> Note: If a maintainer reports your pull request as spam or behavior not in line with the project’s code of conduct, you will be ineligible to participate. Also, this year, the first 50,000 participants who successfully complete the challenge will earn a T-shirt.

## How to contribute
Submit your pull request here for Hacktoberfest-2021 in any language you prefer, if language folder not present, create one as a part of it, after script add your name and GitHub profile into Contributors.md file.

#### Instructions:

*Make sure you have a GitHub account. In case you don't have one, you can create your account by visiting https://github.com/ and clicking on ``Sign up`` option at the top right corner.*

### 1. Register yourself for Hacktoberfest
###### Link to register: https://hacktoberfest.digitalocean.com/
Click on "Start Hacking" and add your GitHub account.


### 2. Star and Fork this Repository
###### You can star and fork this repository on GitHub by navigating at the top of this repository.

![Fork this repository](https://camo.githubusercontent.com/b22b37874052e69f2e83743b5763440aec7af332e6ea51df6b86652a343d8b6e/68747470733a2f2f68656c702e6769746875622e636f6d2f6173736574732f696d616765732f68656c702f7265706f7369746f72792f666f726b5f627574746f6e2e6a7067)

GitHub repository URLs will reference both the username associated with the owner of the repository, as well as the repository name. For example, dscvitpune is the owner of the Hacktoberfest repository, so the GitHub URL for this project is:
https://github.com/dscvitpune/dsc-hacktoberfest-2021

Once you fork this repository, your account will have a copy of this repository but any changes made to it will not directly affect the original (i.e. this) repository.
URL for your repository will be similar to https://github.com/your-username/dsc-hacktoberfest-2021


### 3. Clone the Repository

To make a local copy of the forked repository, let’s first open up a terminal window.

We’ll use the `git clone`  command along with the URL that points to your fork of the repository.

This URL will be similar to the URL above, except now it will end with `.git.` The URL will look like this: https://github.com/your-username/dsc-hacktoberfest-2021.git

You can alternatively copy the URL by using the green “Code” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL
![Copy the URL using the Code button](https://camo.githubusercontent.com/7874a18f4d58d18ef485cdae8acae5e0591f02c7ed955bb7ad9d111153a20da8/68747470733a2f2f646f63732e6769746875622e636f6d2f6173736574732f696d616765732f68656c702f7265706f7369746f72792f636f64652d627574746f6e2e706e67)

Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

`git clone https://github.com/your-username/dsc-hacktoberfest-2021.git`


### 4. Create a New Branch

To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to switch into that directory.

#####    `cd dsc-hacktoberfest-2021/`

Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.


##### `git branch new-branch`

Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### ` git checkout new-branch `

Once you enter the git `checkout` command, you will receive the following output:

######  `Output:`
#####  `Switched to branch 'new-branch' `


At this point, you can now modify existing files or add new files to the project on your own branch.

#### Make Changes Locally

Once you have modified existing files or added new files to the project, you can add them to your local repository, which you can do with the git add command. Let’s add the -A flag to add all changes that we have made:

##### ` git add -A ` or ` git add . `

Next, we’ll want to record the changes that we made to the repository with the git commit command.

*The commit message is an important aspect of your code contribution; it helps the other contributors fully understand the change you have made, why you made it, and how significant it is. Additionally, commit messages provide a historical record of the changes for the project at large, helping future contributors along the way.*


If you have a very short message, you can record that with the -m flag and the message in quotes:

###### ` Example: `
##### ` git commit -m "Updated Readme.md" `

###### At this point you can use the git push command to push the changes to the current branch of your forked repository:
###### ` Example:`
##### ` git push --set-upstream origin new-branch `

### 5. Update Local Repository

*While working on a project alongside other contributors, it is important for you to keep your local repository up-to-date with the project as you don’t want to make a pull request for code that will cause conflicts. To keep your local copy of the code base updated, you’ll need to sync changes.*

We’ll first go over configuring a remote for the fork, then syncing the fork.

### 6. Configure a Remote for the Fork

Next up, you’ll have to specify a new remote upstream repository for us to sync with the fork. This will be the original repository that you forked from. you’ll have to do this with the git remote add command.

##### ` git remote add upstream https://github.com/your-username/dsc-hacktoberfest-2021.git `

In this example, // upstream // is the shortname we have supplied for the remote repository since in terms of Git, “upstream” refers to the repository that you cloned from. If you want to add a remote pointer to the repository of a collaborator, you may want to provide that collaborator’s username or a shortened nickname for the shortname.

### 7. Sync the Fork

Once you have configured a remote that references the upstream and original repository on GitHub, you are ready to sync your fork of the repository to keep it up-to-date.
To sync your fork, from the directory of your local repository in a terminal window, you’ll have to use the // git fetch // command to fetch the branches along with their respective commits from the upstream repository. Since you used the shortname “upstream” to refer to the upstream repository, you’ll have to pass that to the command:

##### ` git fetch upstream `

Switch to the local master branch of our repository:

##### ` git checkout master `

Now merge any changes that were made in the original repository’s master branch, that you will access through your local upstream/master branch, with your local master branch:

##### ` git merge upstream/master `

### 8. Create Pull Request

At this point, you are ready to make a pull request to the original repository.

Navigate to your forked repository, and press the “New pull request” button on your left-hand side of your Repo page.
![Create a new pull request](https://camo.githubusercontent.com/d5e050413f7273d4fe87ab6d855e810c8002eec2ad2d5e7fd7d4d30c18318412/68747470733a2f2f68656c702e6769746875622e636f6d2f6173736574732f696d616765732f68656c702f70756c6c5f72657175657374732f63686f6f73652d626173652d616e642d636f6d706172652d6272616e636865732e706e67)

## 🎉 Hurray! 🎉 
#### You just got closer to completing your Hacktoberfest challenge.


## Support

Check [Contribution](/CONTRIBUTION.md) Guide Before Contribution.
