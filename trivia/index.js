//run script aftere DOM get loaded
document.addEventListener('DOMContentLoaded', function(){

    //change color and give feedback for the correct answer
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function(){
        correct.style.backgroundColor = 'lightgreen';
        document.querySelector('#fb1').innerHTML = 'Correct!';
    });

    //when answer is incorrect, change color to red
    let incorrect = document.querySelector('.incorrect');
    for (let i = 0; i < incorrect.length; i++) {
        incorrect[i].addEventListener('click', function(){
            incorrect[i].style.backgroundColor = 'red';
            document.querySelector('#fb1').innerHTML = 'Incorrect!';
        });
        
    }
    //    free response question answer
    document.querySelector('#check').addEventListener('click', function(){
        let input = document.querySelector('input');
        if (input === "India" || input === "india" ) {
            input.style.backgroundColor = 'lightgreen';
            document.querySelector('#fb2').innerHTML = 'Correct!';
            
        } else {
            input.style.backgroundColor = 'red';
            document.querySelector('#fb2').innerHTML = 'Incorrect!';
        }
    });

})
