function validateForm() {
 
  var fname = document.forms["myForm"]["fname"].value;
  var lname = document.forms["myForm"]["lname"].value;
  var dob = document.forms["myForm"]["dob"].value;
  var mobile = document.forms["myForm"]["ph"].value;
  var course = document.querySelector('input[name="course"]:checked');

  
  var fnameWarning = document.getElementById("fnameWarning");
  var lnameWarning = document.getElementById("lnameWarning");
  var dobWarning = document.getElementById("dobWarning");
  var mobileWarning = document.getElementById("mobileWarning");
  var courseWarning = document.getElementById("courseWarning");


  fnameWarning.innerHTML = "";
  lnameWarning.innerHTML = "";
  dobWarning.innerHTML = "";
  mobileWarning.innerHTML = "";
  courseWarning.innerHTML = "";

 
  if (fname.trim() === "") {
    fnameWarning.innerHTML = "First Name should not be blank";
    document.myForm.fname.focus();
    return false;
  }
  if (lname.trim() === "") {
    lnameWarning.innerHTML = "Second Name should not be blank";
    document.myForm.lname.focus();
    return false;
  }

  if (dob === "") {
    dobWarning.innerHTML = "Please select the Date of Birth";
    document.myForm.dob.focus();
    return false;
  }

  const datePattern = /^\d{2}\/\d{2}\/\d{4}$/;

  if (!datePattern.test(dob)) {
    document.getElementById("dobWarning").innerHTML =
      "Invalid date format. use dd/mm/yyyy.";
    document.myForm.dob.focus();
    return false;
  }

  const parts = dob.split("/");
  const day = parseInt(parts[0], 10);
  const month = parseInt(parts[1], 10);
  const year = parseInt(parts[2], 10);

  if (day < 1 || day > 31 || month < 1 || month > 12) {
    document.getElementById("dobWarning").innerHTML =
      "Invalid day or month values.";
    document.myForm.dob.focus();
    return false;
  }

  
  if (mobile.length !== 10) {
    mobileWarning.innerHTML = "Mobile number should be 10 digits long";
    document.myForm.ph.focus();
    return false;
  }


  if (!course) {
    courseWarning.innerHTML = "Please select a course";
    return false;
  }

  alert("Form submitted Successfully");
  return true;
}
