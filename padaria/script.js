
// ========================================
// CONFIGURAÇÕES
// ========================================

const WHATSAPP = "5541998892366";

const produtos = [

    // PÃES
    {
        id: 1,
        nome: "Pão Francês",
        descricao: "Crocante por fora e macio por dentro.",
        preco: 1.00,
        imagem: "pao-frances.jpg",
        categoria: "🥖 Pães e Panificados"
    },
    {
        id: 2,
        nome: "Pão de Queijo",
        descricao: "Quentinho, macio e cheio de sabor.",
        preco: 4.00,
        imagem: "pao-de-queijo.jpg",
        categoria: "🥖 Pães e Panificados"
    },
    {
        id: 3,
        nome: "Pão de Leite",
        descricao: "Leve, fofinho e perfeito para o café.",
        preco: 2.50,
        imagem: "pao-de-leite.jpg",
        categoria: "🥖 Pães e Panificados"
    },
    {
        id: 4,
        nome: "Pão Integral",
        descricao: "Uma opção deliciosa para seu dia.",
        preco: 12.00,
        imagem: "pao-integral.jpg",
        categoria: "🥖 Pães e Panificados"
    },

    // BOLOS E TORTAS
    {
        id: 5,
        nome: "Bolo de Chocolate",
        descricao: "Massa fofinha com cobertura cremosa.",
        preco: 8.00,
        imagem: "bolo-chocolate.jpg",
        categoria: "🍰 Bolos e Tortas"
    },
    {
        id: 6,
        nome: "Bolo de Cenoura",
        descricao: "Com aquela deliciosa cobertura de chocolate.",
        preco: 7.00,
        imagem: "bolo-cenoura.jpg",
        categoria: "🍰 Bolos e Tortas"
    },
    {
        id: 7,
        nome: "Bolo de Fubá",
        descricao: "Tradicional, macio e com gostinho de casa.",
        preco: 6.00,
        imagem: "bolo-fuba.jpg",
        categoria: "🍰 Bolos e Tortas"
    },
    {
        id: 8,
        nome: "Torta de Morango",
        descricao: "Creme suave com morangos fresquinhos.",
        preco: 10.00,
        imagem: "torta-morango.jpg",
        categoria: "🍰 Bolos e Tortas"
    },

    // SALGADOS
    {
        id: 9,
        nome: "Coxinha de Frango",
        descricao: "Massa douradinha com recheio saboroso.",
        preco: 7.00,
        imagem: "coxinha.jpg",
        categoria: "🥟 Salgados"
    },
    {
        id: 10,
        nome: "Empada",
        descricao: "Massa delicada com recheio delicioso.",
        preco: 6.00,
        imagem: "empada.jpg",
        categoria: "🥟 Salgados"
    },
    {
        id: 11,
        nome: "Pastel",
        descricao: "Crocante e recheado na medida certa.",
        preco: 8.00,
        imagem: "pastel.jpg",
        categoria: "🥟 Salgados"
    },
    {
        id: 12,
        nome: "Pão Pizza",
        descricao: "Uma combinação deliciosa de sabores.",
        preco: 7.50,
        imagem: "pao-pizza.jpg",
        categoria: "🥟 Salgados"
    },

    // DOCES E SOBREMESAS
    {
        id: 13,
        nome: "Brigadeiro",
        descricao: "Tradicional, cremoso e cheio de chocolate.",
        preco: 3.50,
        imagem: "brigadeiro.jpg",
        categoria: "🍫 Doces e Sobremesas"
    },
    {
        id: 14,
        nome: "Pudim",
        descricao: "Textura cremosa com calda de caramelo.",
        preco: 8.00,
        imagem: "pudim.jpg",
        categoria: "🍫 Doces e Sobremesas"
    },
    {
        id: 15,
        nome: "Sonho de Creme",
        descricao: "Massa fofinha com recheio irresistível.",
        preco: 6.00,
        imagem: "sonho.jpg",
        categoria: "🍫 Doces e Sobremesas"
    },
    {
        id: 16,
        nome: "Brownie",
        descricao: "Intenso sabor de chocolate em cada pedaço.",
        preco: 7.00,
        imagem: "brownie.jpg",
        categoria: "🍫 Doces e Sobremesas"
    }

];


// ========================================
// CARRINHO
// ========================================

let carrinho = [];


// ========================================
// FORMATAÇÃO DE PREÇO
// ========================================

function formatarPreco(valor) {
    return valor.toLocaleString("pt-BR", {
        style: "currency",
        currency: "BRL"
    });
}


// ========================================
// MOSTRAR PRODUTOS
// ========================================

function mostrarProdutos() {

    const lista = document.getElementById("lista-produtos");

    const categorias = [...new Set(
        produtos.map(produto => produto.categoria)
    )];

    lista.innerHTML = categorias.map(categoria => {

        const produtosCategoria = produtos.filter(
            produto => produto.categoria === categoria
        );

        return `
            <div class="categoria-cardapio">

                <h3>${categoria}</h3>

                <p>Preparados com carinho para você.</p>

            </div>

            <div class="cardapio-produtos">

                ${produtosCategoria.map(produto => `

                    <article class="produto-card">

                        <img
                            src="./imagens/${produto.imagem}"
                            alt="${produto.nome}"
                            loading="lazy"
                        >

                        <div class="produto-info">

                            <h3>${produto.nome}</h3>

                            <p>${produto.descricao}</p>

                            <span class="preco">
                                ${formatarPreco(produto.preco)}
                            </span>

                            <button
                                class="botao-pedido"
                                data-adicionar="${produto.id}"
                            >
                                🛒 Adicionar ao carrinho
                            </button>

                        </div>

                    </article>

                `).join("")}

            </div>

        `;

    }).join("");

}


// ========================================
// ADICIONAR AO CARRINHO
// ========================================

function adicionarCarrinho(id) {

    const produto = produtos.find(
        item => item.id === Number(id)
    );

    if (!produto) return;

    const itemExistente = carrinho.find(
        item => item.id === produto.id
    );

    if (itemExistente) {

        itemExistente.quantidade++;

    } else {

        carrinho.push({
            ...produto,
            quantidade: 1
        });

    }

    atualizarCarrinho();

}


// ========================================
// ALTERAR QUANTIDADE
// ========================================

function alterarQuantidade(id, operacao) {

    const item = carrinho.find(
        produto => produto.id === Number(id)
    );

    if (!item) return;

    if (operacao === "mais") {
        item.quantidade++;
    }

    if (operacao === "menos") {
        item.quantidade--;
    }

    if (item.quantidade <= 0) {

        carrinho = carrinho.filter(
            produto => produto.id !== Number(id)
        );

    }

    atualizarCarrinho();

}


// ========================================
// REMOVER PRODUTO
// ========================================

function removerProduto(id) {

    carrinho = carrinho.filter(
        produto => produto.id !== Number(id)
    );

    atualizarCarrinho();

}


// ========================================
// CALCULAR VALORES
// ========================================

function calcularSubtotal() {

    return carrinho.reduce((total, item) => {

        return total + Math.round(item.preco * 100) * item.quantidade;

    }, 0);

}


// ========================================
// ATUALIZAR CARRINHO
// ========================================

function atualizarCarrinho() {

    const itens = document.getElementById("carrinho-itens");

    const vazio = document.getElementById("carrinho-vazio");

    const resumo = document.getElementById("carrinho-resumo");

    const contador = document.getElementById("carrinho-contador");

    const quantidadeTotal = carrinho.reduce(
        (total, item) => total + item.quantidade,
        0
    );

    const subtotal = calcularSubtotal();

    contador.textContent =
        `${quantidadeTotal} ${quantidadeTotal === 1 ? "item" : "itens"}`;

    // Carrinho vazio

    if (carrinho.length === 0) {

        vazio.style.display = "block";
        resumo.style.display = "none";
        itens.innerHTML = "";

    } else {

        vazio.style.display = "none";
        resumo.style.display = "block";

        itens.innerHTML = carrinho.map(item => {

            const totalItem =
                Math.round(item.preco * 100) * item.quantidade;

            return `

                <div class="carrinho-item">

                    <div class="carrinho-produto">

                        <img
                            src="./imagens/${item.imagem}"
                            alt="${item.nome}"
                        >

                        <div>
                            <h3>${item.nome}</h3>

                            <p>${formatarPreco(item.preco)} cada</p>

                            <strong>
                                ${formatarPreco(totalItem / 100)}
                            </strong>
                        </div>

                    </div>

                    <div class="controle-quantidade">

                        <button
                            data-acao="menos"
                            data-id="${item.id}"
                            aria-label="Diminuir quantidade"
                        >−</button>

                        <span>${item.quantidade}</span>

                        <button
                            data-acao="mais"
                            data-id="${item.id}"
                            aria-label="Aumentar quantidade"
                        >+</button>

                    </div>

                    <button
                        class="remover-item"
                        data-remover="${item.id}"
                    >
                        Remover
                    </button>

                </div>

            `;

        }).join("");

    }

    document.getElementById("subtotal").textContent =
        formatarPreco(subtotal / 100);

    document.getElementById("total").textContent =
        formatarPreco(subtotal / 100);

}


// ========================================
// LIMPAR CARRINHO
// ========================================

function limparCarrinho() {

    carrinho = [];

    atualizarCarrinho();

}


// ========================================
// FINALIZAR PEDIDO PELO WHATSAPP
// ========================================

function finalizarPedido() {

    if (carrinho.length === 0) {

        alert("Adicione pelo menos um produto ao carrinho!");

        return;

    }

    let mensagem = "*🍞 DOCE IMPÉRIO - NOVO PEDIDO*\n\n";

    mensagem += "*Olá! Gostaria de fazer o seguinte pedido:*\n\n";

    carrinho.forEach(item => {

        const totalItem =
            Math.round(item.preco * 100) * item.quantidade;

        mensagem += `*${item.nome}*\n`;

        mensagem += `Quantidade: ${item.quantidade}\n`;

        mensagem += `Valor unitário: ${formatarPreco(item.preco)}\n`;

        mensagem += `Subtotal: ${formatarPreco(totalItem / 100)}\n\n`;

    });

    const subtotal = calcularSubtotal();

    mensagem += "--------------------------\n";

    mensagem += `*TOTAL DO PEDIDO: ${formatarPreco(subtotal / 100)}*\n\n`;

    mensagem += "Pagamento: a combinar pelo WhatsApp.\n\n";

    mensagem += "Aguardo a confirmação do pedido. Obrigado! 😊";

    const url =
        `https://wa.me/${WHATSAPP}?text=${encodeURIComponent(mensagem)}`;

    window.open(url, "_blank", "noopener,noreferrer");

}


// ========================================
// EVENTOS
// ========================================

// Adicionar produtos

document.getElementById("lista-produtos").addEventListener("click", function(event) {

    const botao = event.target.closest("[data-adicionar]");

    if (!botao) return;

    adicionarCarrinho(botao.dataset.adicionar);

});


// Controles do carrinho

document.getElementById("carrinho-itens").addEventListener("click", function(event) {

    const quantidade = event.target.closest("[data-acao]");

    const remover = event.target.closest("[data-remover]");

    if (quantidade) {

        alterarQuantidade(
            quantidade.dataset.id,
            quantidade.dataset.acao
        );

    }

    if (remover) {

        removerProduto(remover.dataset.remover);

    }

});


// Finalizar pedido

document.getElementById("finalizar-pedido").addEventListener("click", finalizarPedido);


// Limpar carrinho

document.getElementById("limpar-carrinho").addEventListener("click", limparCarrinho);


// ========================================
// INICIALIZAÇÃO
// ========================================

mostrarProdutos();

atualizarCarrinho();
