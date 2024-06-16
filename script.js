var heroCursor = document.querySelector(".hero-cursor");
var heroSection = document.querySelector(".hero-content");
var heroSectionMain = document.querySelector("#hero");
var menuBar = document.querySelector(".menu");

function mouseHover() {
  heroSection.addEventListener("mousemove", (dets) => {
    gsap.to(heroCursor, {
      left: dets.x,
      top: dets.y,
      ease: "power1.out",
    });
  });
  heroSectionMain.addEventListener("mouseenter", () => {
    gsap.to(heroCursor, {
      scale: 1,
      opacity: 1,
    });
  });
  heroSectionMain.addEventListener("mouseleave", () => {
    gsap.to(heroCursor, {
      scale: 0,
      opacity: 0,
    });
  });
  menuBar.addEventListener("mouseenter", () => {
    gsap.to(heroCursor, {
      scale: 0,
      opacity: 0,
    });
  });
  menuBar.addEventListener("mouseleave", () => {
    gsap.to(heroCursor, {
      scale: 1,
      opacity: 1,
    });
  });
}

var btn = document.querySelectorAll(".btn");
btn.forEach((elem) => {
  elem.addEventListener("mouseover", () => {
    gsap.to(elem.querySelector("span"), {
      width: "100%",
      left: "0",
    });
  });
  elem.addEventListener("mouseleave", () => {
    var tempTl = gsap.timeline();
    tempTl.to(elem.querySelector("span"), {
      width: "0%",
      left: "100%",
    });
    tempTl.to(elem.querySelector("span"), {
      width: "0%",
      left: "0%",
      right: "100%",
      duration: 0,
    });
  });
});

function menuAnimation() {
  menuBar.onclick = () => {
    menuBar.classList.toggle("active");
    heroSectionMain.classList.toggle("active");
    gsap.to(".navbar-video", {
      scale: 1,
      delay: 0.4,
      duration: 1.5,
      ease: "power3",
    });
    gsap.from(".navbar-main ul li", {
      y: 100,
      opacity: 0,
      delay: 0.6,
      ease: "expo.out",
      stagger: 0.05,
      duration: 1,
    });
    gsap.from(".navbar-footer h1 , navbar-footer a", {
      x: 100,
      opacity: 0,
      delay: 0.6,
      stagger: 0.05,
      duration: 1,
    });
    gsap.to(".navbar-main ul", {
      opacity: 1,
      ease: "power4.in",
      y: 0,
    });
    gsap.from(".navbar-hr", {
      width: "30%",
      duration: 1,
      delay: 0.5,
    });
  };
  document.querySelector(".close-btn").onclick = () => {
    menuBar.classList.remove("active");
    heroSectionMain.classList.remove("active");
    gsap.to(".navbar-video", {
      scale: 0,
      duration: 1.5,
      ease: "power3",
    });
    gsap.to(".navbar-main ul", {
      y: 200,
      ease: "power4.in",
      opacity: 0,
      ease: "expo.out",
      duration: 1.5,
    });
  };
}
function page2Animation()
{
    

gsap.to(".page2-hr", {
    width: "100%",
    ease: "power2.out",
    scrollTrigger: {
      trigger: "#page2",
      scroller: "body",
      start: "top 47%",
      end: "top 30%",
      scrub: 3,
    },
  });


if (window.matchMedia("(min-width : 900px)").matches) {
  var content = document.querySelector(".page2-main p").textContent;
  const linesSpans = content.split(/\s+/);
  var page2Lines = document.querySelector(".page2-main");

  page2Lines.innerHTML = "";
  var page2MainLine = "";
  linesSpans.forEach((ele) => {
    ele += "&nbsp;";
    page2MainLine += `<p>${ele}</p> `;
  });
  page2Lines.innerHTML = page2MainLine;

  gsap.from(".page2-main p , .page2-header-main h1", {
    y: 100,
    stagger: 0.4,
    duration: 3,
    skewY: -7,
    ease: "power2.out",
    opacity: 0,
    scrollTrigger: {
      trigger: "#page2",
      scroller: "body",
      start: "top 47%",
      end: "top 10%",
      scrub: 3,
    },
  });
} else {
  gsap.from(".page2-main p , .page2-header-main h1", {
    y: 100,
    stagger: 0.4,
    duration: 3,
    skewY: -7,
    ease: "power2.out",
    opacity: 0,
    scrollTrigger: {
      trigger: "#page2",
      scroller: "body",
      start: "top 47%",
      end: "top 47%",
      scrub: 3,
    },
  });
}
}
mouseHover();
menuAnimation();
page2Animation();


