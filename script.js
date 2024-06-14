var heroCursor = document.querySelector(".hero-cursor");
var heroSection = document.querySelector(".hero-content");
var heroSectionMain = document.querySelector("#hero");


heroSection.addEventListener("mousemove", (dets) => {

    gsap.to(heroCursor, {
        left: dets.x,
        top: dets.y,
        ease: "power1.out",
    })
})
heroSectionMain.addEventListener("mouseenter", () => {

    gsap.to(heroCursor, {
        scale: 1,
        opacity : 1,
    })
})
heroSectionMain.addEventListener("mouseleave", () => {

    gsap.to(heroCursor, {
        scale: 0,
        opacity : 0,
    })
})


var btn = document.querySelectorAll(".btn");
btn.forEach((elem) => {
    
    
    elem.addEventListener("mouseover", () => {
        
        gsap.to(elem.querySelector("span"), {
            width: "100%",
            left: "0",
        }) 
    })
    elem.addEventListener("mouseleave", () => {
        var tempTl = gsap.timeline();
        tempTl.to(elem.querySelector("span"), {
            width: "0%",
            left : "100%"
        }) 
        tempTl.to(elem.querySelector("span"), {
            width: "0%",
            left: "0%",
            right: "100%",
            duration : 0,
        }) 
       
    })
    
})