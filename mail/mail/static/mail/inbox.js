document.addEventListener('DOMContentLoaded', function () {

  // Use buttons to toggle between views
  document.querySelector('#inbox').addEventListener('click', () => load_mailbox('inbox'));
  document.querySelector('#sent').addEventListener('click', () => load_mailbox('sent'));
  document.querySelector('#archived').addEventListener('click', () => load_mailbox('archive'));
  document.querySelector('#compose').addEventListener('click', compose_email);

  document.querySelector('#compose-form').addEventListener('submit', (event) => {
    event.preventDefault();

    const recipients = document.querySelector('#compose-recipients').value;
    const subject = document.querySelector('#compose-subject').value;
    const body = document.querySelector('#compose-body').value;

    fetch('/emails', {
      method: 'POST',
      body: JSON.stringify({
        recipients: recipients,
        subject: subject,
        body: body
      })
    })
      .then(response => response.json())
      .then(result => {
        // Print result
        console.log(result);
        load_mailbox('sent')
      });
  });

  // By default, load the inbox
  load_mailbox('inbox');
});

function compose_email() {

  // Show compose view and hide other views
  document.querySelector('#emails-view').style.display = 'none';
  document.querySelector('#compose-view').style.display = 'block';
  document.querySelector('#email-details').style.display = 'none';

  // Clear out composition fields
  document.querySelector('#compose-recipients').value = '';
  document.querySelector('#compose-subject').value = '';
  document.querySelector('#compose-body').value = '';
}

function view_email(id) {
  fetch(`/emails/${id}`)
    .then(response => response.json())
    .then(email => {
      // console.log(email);
      document.querySelector('#email-details').style.display = 'block';
      document.querySelector('#emails-view').style.display = 'none';
      document.querySelector('#compose-view').style.display = 'none';

      document.querySelector('#email-details').innerHTML = `
      <ul class="list-group">
      <li class="list-group-item"><b>From:</b> ${email.sender}</li>
      <li class="list-group-item"><b>To:</b> ${email.recipients}</li>
      <li class="list-group-item"><b>Subject:</b> ${email.subject}</li>
      <li class="list-group-item"><b>Subject:</b> ${email.timestamp}</p>
      </ul>
      <hr>
      <div id="email-body">${email.body}</div>
      `

      // change to read.
      if (!email.read) {
        fetch(`/emails/${email.id}`, {
          method: 'PUT',
          body: JSON.stringify({
            read: true
          })
        })
      }

      // archive.
      const btn_arch = document.createElement('button');
      btn_arch.innerHTML = email.archived ? "Unarchive" : "Archive";
      btn_arch.className = email.archived ? "btn btn-success" : "btn btn-danger";
      btn_arch.addEventListener('click', function () {
        fetch(`/emails/${email.id}`, {
          method: 'PUT',
          body: JSON.stringify({
            archived: !email.archived
          })
        })
          .then(() => { load_mailbox('archive') })
      });
      document.querySelector('#email-details').append(btn_arch);
      //Reply.
      const btn_reply = document.createElement('button');
      btn_reply.innerHTML = "Reply";
      btn_reply.className = "btn btn-sm btn-outline-primary";
      btn_reply.style.marginLeft = '10px';
      btn_reply.addEventListener('click', function () {
        compose_email();
        document.querySelector("#compose-recipients").value = email.sender;
        let subject = email.subject;
        if(subject.split(' ',1)[0] != "Re:"){
          subject = "Re:"+ email.subject;
        }
        document.querySelector("#compose-subject").value = subject;
        document.querySelector("#compose-body").value = `On ${email.timestamp} ${email.sender} wrote: ${email.body}`;
      });
      document.querySelector('#email-details').append(btn_reply);
    });
}

function load_mailbox(mailbox) {

  // Show the mailbox and hide other views
  document.querySelector('#emails-view').style.display = 'block';
  document.querySelector('#compose-view').style.display = 'none';
  document.querySelector('#email-details').style.display = 'none';

  // Show the mailbox name
  document.querySelector('#emails-view').innerHTML = `<h3>${mailbox.charAt(0).toUpperCase() + mailbox.slice(1)}</h3>`;

  // Get the email for that mailbox and user
  fetch(`/emails/${mailbox}`)
    .then(response => response.json())
    .then(emails => {
      // loop through email and create a div for card.
      emails.forEach(singleEmail => {
        // console.log(singleEmail);
        // create card for each email.
        const emailCard = document.createElement('div');
        // emailCard.className = "list-group-item";
        emailCard.innerHTML = `
        <span>${singleEmail.sender}</span>
        <span>${singleEmail.subject}</span>
        <span>${singleEmail.timestamp}</span>
        `
          ;

        // changing background color on the basis of email read it or not!
        emailCard.className = singleEmail.read ? 'read' : 'unread';

        // Add click event to view email
        emailCard.addEventListener('click', function () {
          view_email(singleEmail.id);
        });
        document.querySelector('#emails-view').append(emailCard);
        emailCard.children[0].style.fontWeight = 'bold';
        emailCard.children[2].style.color = 'grey';
        emailCard.style.display = 'grid';
        emailCard.style.justifyContent = 'start';
        emailCard.style.gridTemplateColumns = '22% 60% 18%'
      })
    });
}

