function add(num1,num2,cb) {
    let result=num1+num2;
    cb(result);
}


function display(result) {
    console.log(result);
}

add(10,20,(r)=>{
    display(r);
});