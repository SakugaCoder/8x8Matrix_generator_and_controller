let num_rows = 8;
let num_cols = 8;

window.onload = function(){
    matrix = document.querySelector(".matrix");
    for(i = 0; i < num_rows; i++){
        let row_html = '<div class="row">'
        let col_html = '';
        for(c = 0; c < num_cols; c++){
            let cell_num =   ""+String(i + 1) + "" + String(c + 1)
            col_html += '<div class="cell cell-'+cell_num+'" onclick="changeClass(this);"> </div>'
        }
        row_html += col_html
        row_html += '</div>';
        matrix.innerHTML += row_html;
    }
}

function changeClass(elm){
    $(elm).toggleClass('selected');
    console.log($(elm))
}

function deleteArray(){
    $(".cell").removeClass("selected");
    $(".result").val("");
}

function generateArray(){
    console.log("Generando array");
    let final_array = "{{";
    for(i = 1; i <= num_rows; i++){
        final_array += "\t{";
        for(c = 1; c <= num_cols; c++){
            let cell_num =   ""+String(i) + "" + String(c);
            console.log("We are in "+cell_num);
            if( $(".cell-"+cell_num).hasClass("selected")){
                final_array += "1"
            }
            else{
                final_array += "0"
            }

            if(c != num_cols){
                final_array += ", ";
            }
        }
        final_array += "}"
        if(c != num_rows){
            final_array += ",";
        }
        final_array += "\n";

        
    }
    final_array += "}}";

    $(".result").val(final_array);
}