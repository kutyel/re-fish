type lineAttrs = {
    x1: string,
    y1: string,
    x2: string,
    y2: string,
    stroke: string
  };
  
[@react.component]
let make = (~size: string) => {
    let style = ReactDOMRe.Style.make(~width=size, ~height=size,());
    let la1 = {
        x1: "50",
        y1: "60",
        x2: "150",
        y2: "160",
        stroke: "green"
    };
    let la2 = {
        x1: "110",
        y1: "120",
        x2: "50",
        y2: "90",
        stroke: "blue"
    };
    let lines = [|la1, la2|];
    <svg
      style
      xmlns="http://www.w3.org/2000/svg">
      <path
        d="M10.99845 11.78V5.5c-.03-.78-.34-1.47-.94-2.06-.6-.59-1.28-.91-2.06-.94h-1v-2l-3 3 3 3v-2h1c.27.02.48.11.69.31.21.2.3.42.31.69v6.28c-.78283.4509-1.16446 1.37196-.92994 2.2444.23452.87242 1.02654 1.47799 1.92994 1.4756.9034.00239 1.69541-.60318 1.92994-1.4756.23452-.87244-.14711-1.7935-.92994-2.2444zm-1 2.92c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm-6-11.2c0-1.11-.89-2-2-2-.9034-.00239-1.69542.60318-1.92994 1.4756-.23452.87244.1471 1.7935.92994 2.2444v6.56c-.78283.4509-1.16446 1.37196-.92994 2.2444.23452.87242 1.02654 1.47799 1.92994 1.4756.9034.00239 1.69541-.60318 1.92994-1.4756.23452-.87244-.14711-1.7935-.92994-2.2444V5.22c.59-.34 1-.98 1-1.72zm-.8 10c0 .66-.55 1.2-1.2 1.2-.65 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2zm-1.2-8.8c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"
        fillOpacity=".50008"
        viewBox="0 0 12 16"
      />
      {lines->Belt.Array.map(le => <line x1=le.x1 y1=le.y1 x2=le.x2 y2=le.y2 stroke=le.stroke />)->React.array}
    </svg>;
  };