let audioElm

const chords = [
    {chordId: 'audio1', audioFile: 'audioFile1', buttonId: 'E1'},
    {chordId: 'audio2', audioFile: 'audioFile2', buttonId: 'B2'},
    {chordId: 'audio3', audioFile: 'audioFile3', buttonId: 'G3'},
    {chordId: 'audio4', audioFile: 'audioFile4', buttonId: 'D4'},
    {chordId: 'audio5', audioFile: 'audioFile5', buttonId: 'A5'},
    {chordId: 'audio6', audioFile: 'audioFile6', buttonId: 'E6'}
]

const byChordId = object => object.chordId
const chordsByChordId = chords.map(byChordId)

const byAudioFile = object => object.audioFile
const chordsByAudioFile = chords.map(byAudioFile)

const byButtonId = object => object.buttonId
const chordsByButtonId = chords.map(byButtonId)

const getSongElement = value => document.getElementById(chordsByChordId[value])
const getAudioFile = value => document.getElementById(chordsByAudioFile[value])
const getBtnFile = value => document.getElementById(chordsByButtonId[value])

const playAudio = (audioElm, songFile, btnId, index) => {

    btnId.innerHTML = "Stop " + chordsByButtonId[index]
    audioElm.src = songFile.value
    audioElm.play()

    return "Reproduzindo"
}

const stopAudio = (audioElm, btn, index) => {
    btn.innerHTML = chordsByButtonId[index]
    audioElm.pause()

    return "Parado"
}


//  Alternates between play and pause based on the value of the paused property
const main = (index) => {

    audioElm = getSongElement(index)
    let  audioFile = getAudioFile(index)
    let  btn = getBtnFile(index)

    if(btn.innerHTML == chordsByButtonId[index]) {
        playAudio(audioElm, audioFile, btn, index)

    }else {
        stopAudio(audioElm, btn, index)
    }
}



