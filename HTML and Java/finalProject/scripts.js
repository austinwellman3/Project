function start() {
    document.getElementById("data").rows["seconds"].innerHTML = "Reading Data...";
    document.getElementById("startButton").disabled = true;
    document.getElementById("stopButton").disabled = false;
}
function stop(){
    document.getElementById("data").rows["seconds"].innerHTML = "";
    document.getElementById("startButton").disabled = false;
    document.getElementById("stopButton").disabled = true;
}