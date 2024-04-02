import os

# Define the semesters and subjects
semesters = ["Semester 1", "Semester 2", "Semester 3", "Semester 4", "Semester 5", "Semester 6", "Semester 7", "Semester 8"]
subjects = [
    ["Introduction to ICT", "Programming Fundamentals", "Applied Physics (BS-CS)", "Linear Algebra", "Calculus & Analytical Geometry", "Pakistan Studies", "English Composition & Comprehension"],
    ["Object Oriented Programming", "Digital Logic Design", "Differential Equations (BS-CS)", "Islamic Studies/Ethics", "Communication & Presentation Skills"],
    ["Data Structures", "Discrete Structures", "Probability & Statistics (BS-AI)", "Introduction to Data Science (BS-DS)", "Software Requirements Engineering (BS-SE)", "Human Computer Interaction (BS-SE)"],
    ["Islamic Studies/ Ethics (BS-AI)", "Database Systems", "Computer Organization and Assembly Language", "Fundamentals of Software Engineering (BS-DS)", "Advanced Statistics (BS-DS)", "Fundamentals of Big Data Analytics (BS-DS)", "Software Design & Architecture (BS-SE)"],
    ["University Elective – I (BS-AI)", "Theory of Automata (BS-CS)", "Computer Networks (BS-CS, BS-DS)", "Software Construction & Development (BS-SE)", "Software Quality Engineering (BS-SE)", "Operating Systems (BS-DS, BS-SE)", "Technical & Business Writing (BS-CS, BS-DS)"],
    ["Knowledge Representation & Reasoning (BS-AI)", "Parallel & Distributed Computing (BS-AI, BS-DS)", "Artificial Neural Networks (BS-AI)", "Web Engineering (BS-SE)", "Design and Analysis of Algorithms (BS-AI, BS-CS, BS-DS)", "Computer Networks (BS-DS)"],
    ["Final Year Project – I (BS-AI, BS-CS, BS-DS, BS-SE)", "Computer Vision (BS-AI)", "Fundamentals of Natural Language Processing (BS-AI)", "Information Security", "Professional Practices (BS-CS, BS-DS, BS-SE)"],
    ["Final Year Project – II (BS-AI, BS-CS, BS-DS, BS-SE)", "University Elective – III (BS-AI, BS-DS, BS-SE)", "Artificial Intelligence (BS-DS)", "Data Science Elective-III (BS-DS)", "Data Science Elective-IV (BS-DS)", "Software Re-Engineering (BS-SE)", "SE Elective – III (BS-SE)", "SE Elective – IV (BS-SE)"]
]

# Create folders by semesters and subfolders with subject names in the current directory
for semester, subjects_in_semester in zip(semesters, subjects):
    semester_directory = os.path.join(os.getcwd(), semester)
    
    if not os.path.exists(semester_directory):
        os.makedirs(semester_directory)
    
    for subject in subjects_in_semester:
        if "Elective" in subject:
            # Place elective subjects in the "Electives" folder
            electives_directory = os.path.join(semester_directory, "Electives")
            if not os.path.exists(electives_directory):
                os.makedirs(electives_directory)
            subject_directory = os.path.join(electives_directory, subject)
        else:
            subject_directory = os.path.join(semester_directory, subject)
        
        if not os.path.exists(subject_directory):
            os.makedirs(subject_directory)

print("Folders created successfully!")
