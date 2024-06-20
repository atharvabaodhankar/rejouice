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
function page2Animation() {
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

function page3Animation() {
  document.querySelector(".page3-header-text").onmouseover = () => {
    let p3tl = gsap.timeline();

    p3tl.to(".page3-header-text", {
      "--left": "100%",
    });
    p3tl.to(".page3-header-text", {
      "--left": "-70px",
    });
  };
  document.querySelector(".page3-header-text").onmouseleave = () => {
    let p3tl1 = gsap.timeline();

    p3tl1.to(".page3-header-text", {
      "--left": "100%",
    });
    p3tl1.to(".page3-header-text", {
      "--left": "-70px",
    });
  };

  if (window.matchMedia("(max-width : 500px)").matches) {
    document.querySelector(
      ".page3-header-text"
    ).innerHTML = `<h1><span>Explore our</span></h1> <br>
<h1><span>services</span></h1> <br>
<h1><span>and</span></h1> <br>
<h1><span>engagement models</span></h1> <br>`;
  }

  gsap.from(".page3-header-text h1 span", {
    y: 100,
    opacity: 0,
    ease: "power2.out",
    scrollTrigger: {
      scroller: "body",
      trigger: ".page3-header-text",
      start: "top 70%",
      end: "bottom center",
      scrub: 3,
    },
  });

  if (window.matchMedia("(min-width : 900px)").matches) {
    gsap.from(".p3-box-1", {
      x: 400,
      scale: 0.7,
      opacity: 0,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".page3-grid-main",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });
    gsap.from(".p3-box-2", {
      scale: 0.8,
      opacity: 0.6,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".page3-grid-main",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });

    gsap.from(".p3-box-3", {
      x: -400,
      scale: 0.7,
      opacity: 0,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".page3-grid-main",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });
  } else {
    gsap.from(".p3-box-1", {
      x: 100,
      opacity: 0,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".p3-box-1",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });
    gsap.from(".p3-box-2", {
      x: -100,
      opacity: 0,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".p3-box-2",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });

    gsap.from(".p3-box-3", {
      x: 100,
      scale: 0.7,
      opacity: 0,
      ease: "power2.out",
      scrollTrigger: {
        scroller: "body",
        trigger: ".p3-box-3",
        start: "top 70%",
        end: "bottom center",
        scrub: 3,
      },
    });
  }
}

function page4Animation() {
  gsap.from(".page4-header h1", {
    y: 100,
    opacity: 0,
    skewY: 10,
    scrollTrigger: {
      scroller: "body",
      trigger: ".page4-header",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
  gsap.from(".page4-main p", {
    y: 100,
    opacity: 0,
    skewY: 10,
    skewX: 10,
    scrollTrigger: {
      scroller: "body",
      trigger: ".page4-main",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
  gsap.from(".page4-hr", {
    width: "0%",
    scrollTrigger: {
      scroller: "body",
      trigger: ".page4-header",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
}

function page5Animation() {
  gsap.to("#page5 svg", {
    rotate: "200deg",
    duration: 3,
    scrollTrigger: "#page5",
    ease: "power2",
  });
  gsap.from(".page5-span", {
    opacity: 0,
    y: -100,
    scrollTrigger: {
      trigger: "#page5",
      start: "top 60%",
      end: "top 40%",
      scroller: "body",
      scrub: 3,
    },
  });
}
function page6Animation() {
  gsap.from(".page6-hr", {
    width: "0%",
    scrollTrigger: {
      scroller: "body",
      trigger: ".page6-header",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
  gsap.from(".page6-header h1", {
    y: 100,
    opacity: 0,
    skewX: 10,
    scrollTrigger: {
      scroller: "body",
      trigger: ".page6-header",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
  gsap.from(".page6-main p span", {
    y: 100,
    skewX: 10,
    opacity: 0,
    stagger: 0.2,
    scrollTrigger: {
      scroller: "body",
      trigger: ".page6-main",
      scrub: 2,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
}
function page7Animation() {
  var swiper = new Swiper(".mySwiper", {
    slidesPerView: "auto",
    spaceBetween: 20,
    slidesPerGroup: 1,
    grabCursor: true,
    loop: {
      enabled: true,
      loopedSlides: 5,
      slideShadows: true,
    },
    autoplay: {
      delay: 2000,
    },
    freeMode: true,
  });

  gsap.from(".page7-header-main h2 , .page7-header-main h1", {
    y: 100,
    skewX: 10,
    opacity: 0,
    scrollTrigger: {
      scroller: "body",
      trigger: ".page6-main",
      scrub: 4,
      start: "top 60%",
      end: "bottom 60%",
    },
  });
}

function page8Animation() {
  let page8Section = document.querySelector("#page8");
  let page8Cursor = document.querySelector(".page8-cursor");
  let page8H1 = document.querySelector(".page8-main");

  page8Section.addEventListener("mousemove", (dets) => {
    gsap.to(page8Cursor, {
      left: dets.x,
      top : dets.y
      })
  })
  page8H1.addEventListener("mousemove", () => {
    gsap.to(page8Cursor, {
      scale: 10,
      backgroundColor : "#dbdada",
    })
   
  })
  page8H1.addEventListener("mouseleave", () => {
    gsap.to(page8Cursor, {
      scale: 1,
      backgroundColor : "#00000079",
    })
    
  })
  
  
}

if (window.matchMedia("(min-width : 750px)").matches) {
  mouseHover();
}
menuAnimation();
page2Animation();
page3Animation();
page4Animation();
page5Animation();
page6Animation();
page7Animation();
page8Animation();
